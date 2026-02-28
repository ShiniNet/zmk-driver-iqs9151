# IQS9151 Gesture Specification (Implementation Synced)

この文書は、`iqs9151_work_cb()` / `iqs9151_one_finger_update()` /
`iqs9151_two_finger_update()` / `iqs9151_three_finger_update()` の
**現実装準拠仕様**です。

## 0. 前提

- IC内蔵ジェスチャレジスタ (`0x101C` / `0x101E`) は使用しない。
- IC側ジェスチャ設定ブロック (`0x11F6..0x1217`) への書き込みは行わない。
- 判定は `0x1014..0x102E` の座標・フラグを基準に、ドライバ側状態機械で行う。
- `SHOW_RESET` 検出時は後続判定を打ち切り、状態を即時リセットする。

## 1. 入力フレーム

|項目|アドレス|型|意味|
| - | - | - | - |
|Relative X|`0x1014`|`int16`|相対X移動量|
|Relative Y|`0x1016`|`int16`|相対Y移動量|
|Info Flags|`0x1020`|`uint16`|`SHOW_RESET` 等|
|Trackpad Flags|`0x1022`|`uint16`|`finger_count` / movement / confidence|
|Finger1 X/Y|`0x1024` / `0x1026`|`uint16`|1本指座標|
|Finger2 X/Y|`0x102C` / `0x102E`|`uint16`|2本指座標|

## 2. 正規化ルール

- `finger_count == 0` のとき、`prev_frame` の座標をクリアする。
- `finger1` / `finger2` の confidence が無効、または座標が `0xFFFF` のとき、
  `prev_frame` の値をフォールバックとして使う。
- `SHOW_RESET` のとき:
  - pinch中なら `INPUT_BTN_7` release を送る
  - `hold_button` が押下中なら release を送る
  - 1F/2F/3Fセッションと慣性状態をリセットする

## 3. 判定パラメータ（既定値）

- 共通:
  - `IQS9151_HOLD_MIN_MS = 200` (`CONFIG_INPUT_IQS9151_HOLD_MIN_MS`)
  - `IQS9151_TAP_REENTRY_WINDOW_MS = 30` (固定)
- 1F:
  - `ONE_FINGER_TAP_MAX_MS = 150` (`CONFIG_INPUT_IQS9151_1F_TAP_MAX_MS`)
  - `ONE_FINGER_TAP_MOVE = 25` (`CONFIG_INPUT_IQS9151_1F_TAP_MOVE`)
  - `ONE_FINGER_HOLD_MOVE = 30` (固定)
- 2F:
  - `TWO_FINGER_TAP_MAX_MS = 150` (`CONFIG_INPUT_IQS9151_2F_TAP_MAX_MS`)
  - `TWO_FINGER_TAP_MOVE = 30` (`CONFIG_INPUT_IQS9151_2F_TAP_MOVE`)
  - `TWO_FINGER_HOLD_MOVE = 40` (固定)
  - `TWO_FINGER_SCROLL_START_MOVE = 50` (`CONFIG_INPUT_IQS9151_2F_SCROLL_START_MOVE`)
  - `TWO_FINGER_PINCH_START_DISTANCE = 80` (`CONFIG_INPUT_IQS9151_2F_PINCH_START_DISTANCE`)
  - `TWO_FINGER_RELEASE_PENDING_MAX_MS = 150` (固定)
  - `TWO_FINGER_ONE_LEAD_MAX_MS = 120` (固定)
- 3F:
  - `THREE_FINGER_TAP_MAX_MS = 180` (`CONFIG_INPUT_IQS9151_3F_TAP_MAX_MS`)
  - `THREE_FINGER_TAP_MOVE = 30` (`CONFIG_INPUT_IQS9151_3F_TAP_MOVE`)
  - `THREE_FINGER_HOLD_MOVE = 40` (固定)
  - `THREE_FINGER_RELEASE_PENDING_MAX_MS = 150` (固定)
  - `THREE_FINGER_ONE_LEAD_MAX_MS = 120` (固定)
  - `THREE_FINGER_TWO_LEAD_MAX_MS = 120` (固定)

### 3.1 Kconfig管理パラメータ（ジェスチャ関連）

ドライバ全体の `Kconfig` 一覧は
`documents/iqs9151_kconfig_reference.md` を参照してください。

## 4. ジェスチャ仕様

### 4.1 1F

- 1F Tap:
  - 候補開始: `finger_count==1` かつ
    `prev==0` または `TAP_REENTRY_WINDOW_MS` 内に `finger_count==0`
  - 成立: `finger_count==0` かつ
    `elapsed<=ONE_FINGER_TAP_MAX_MS` かつ `abs(dx/dy)<=ONE_FINGER_TAP_MOVE`
  - 出力: `INPUT_BTN_0` click
- 1F Hold:
  - hold候補:
    - セッション開始時に `hold_candidate=true`
    - `abs(dx)>ONE_FINGER_HOLD_MOVE` または `abs(dy)>ONE_FINGER_HOLD_MOVE` を
      **一度でも超えたら** `hold_candidate=false`（同一接触中は復帰しない）
  - 条件: `hold_candidate==true` かつ `elapsed>=IQS9151_HOLD_MIN_MS` かつ
    `abs(dx/dy)<=ONE_FINGER_HOLD_MOVE` かつ Tap未成立
  - 出力: `INPUT_BTN_0` press（ラッチ）

### 4.2 2F

- 2F Tap:
  - 候補開始:
    - `prev==0` または `TAP_REENTRY_WINDOW_MS` 内に `finger_count==0`
    - または `1->2` one-lead が有効 (`TWO_FINGER_ONE_LEAD_MAX_MS` 内)
  - 候補維持:
    - `elapsed<=TWO_FINGER_TAP_MAX_MS`
    - `abs(centroid_dx/dy)<=TWO_FINGER_TAP_MOVE`
    - `abs(distance_delta)<=TWO_FINGER_TAP_MOVE`
  - 段階リリース:
    - `2->1` で `release_pending` に入り、`TWO_FINGER_RELEASE_PENDING_MAX_MS` 以内の
      `1->0` をTap成立として扱う
  - 出力: `INPUT_BTN_1` click
- 2F Hold:
  - hold候補:
    - セッション開始時に `hold_candidate=true`
    - `abs(centroid_dx/dy)>TWO_FINGER_HOLD_MOVE` または
      `abs(distance_delta)>TWO_FINGER_HOLD_MOVE` を
      **一度でも超えたら** `hold_candidate=false`（同一接触中は復帰しない）
  - 条件: `mode==NONE` かつ `hold_candidate==true` かつ
    `elapsed>=IQS9151_HOLD_MIN_MS` かつ
    `abs(centroid_dx/dy)<=TWO_FINGER_HOLD_MOVE` かつ
    `abs(distance_delta)<=TWO_FINGER_HOLD_MOVE` かつ Tap未成立
  - 出力: `INPUT_BTN_1` press（ラッチ）
- 2F Scroll:
  - 開始: `mode==NONE` かつ
    `max(abs(centroid_dx), abs(centroid_dy)) >= TWO_FINGER_SCROLL_START_MOVE`
  - 出力: `REL_HWHEEL` / `REL_WHEEL`（設定有効軸のみ）
- 2F Pinch:
  - 開始: `mode==NONE` かつ
    `abs(distance_delta) >= TWO_FINGER_PINCH_START_DISTANCE` かつ
    `abs(distance_delta) > max(abs(centroid_dx), abs(centroid_dy))`
  - 出力: `INPUT_BTN_7` press/release + `REL_WHEEL`
- Scroll/Pinch競合:
  - 同時成立時は Scroll 優先で mode 固定

### 4.3 3F

- 3F Tap:
  - 候補開始:
    - `prev==0` または `TAP_REENTRY_WINDOW_MS` 内に `finger_count==0`
    - または `1->3` one-lead (`THREE_FINGER_ONE_LEAD_MAX_MS` 内)
    - または `2->3` two-lead (`THREE_FINGER_TWO_LEAD_MAX_MS` 内、2F tap条件内)
  - 候補維持:
    - `elapsed<=THREE_FINGER_TAP_MAX_MS`
    - `abs(dx/dy)<=THREE_FINGER_TAP_MOVE`（`finger1` 追跡）
  - 段階リリース:
    - `3->(2/1)` で `release_pending` に入り、
      `THREE_FINGER_RELEASE_PENDING_MAX_MS` 以内の `->0` をTap成立として扱う
  - 出力: `INPUT_BTN_2` click
- 3F Hold:
  - hold候補:
    - セッション開始時に `three_hold_candidate=true`
    - `abs(dx)>THREE_FINGER_HOLD_MOVE` または `abs(dy)>THREE_FINGER_HOLD_MOVE` を
      **一度でも超えたら** `three_hold_candidate=false`（同一接触中は復帰しない）
  - 条件: `three_hold_candidate==true` かつ `elapsed>=IQS9151_HOLD_MIN_MS` かつ
    `abs(dx/dy)<=THREE_FINGER_HOLD_MOVE` かつ Tap未成立
  - 出力: `INPUT_BTN_2` press（ラッチ）
- 3F Swipe:
  - 条件: `abs(dx)` または `abs(dy)` が
    `CONFIG_INPUT_IQS9151_3F_SWIPE_THRESHOLD` を超過
  - 出力: 方向別 `INPUT_BTN_3/4/5/6` click
  - 1ショット: 成立後に `three_swipe_sent=true` を保持し、
    3本指接触が終了するまで同一接触中は再送しない
- Hold/Swipe競合:
  - 同時成立時は Hold 優先

## 5. 優先度・排他

- Tap/Hold競合は `tap_possible` 条件で排他し、Tap候補中はHoldを出さない。
- Hold は move閾値超過で候補を失効し、同一接触中に再成立しない。
- `hold_button` は単一ラッチ。
  別Tap/Hold成立時は先に既存holdをreleaseし、新イベントは同フレーム抑止する。
- 遷移フレームでは、旧セッション終了処理と新セッション開始判定を同一フレームで扱う。
  そのため `1->2`, `1->3`, `2->3` の lead 判定をサポートする。

## 6. 出力イベント

- Click:
  - 1F Tap: `INPUT_BTN_0` (press + release)
  - 2F Tap: `INPUT_BTN_1` (press + release)
  - 3F Tap: `INPUT_BTN_2` (press + release)
- Hold:
  - 1F/2F/3F Hold: `INPUT_BTN_0/1/2` press（別Tap/Holdでrelease）
- Swipe:
  - 3F: `INPUT_BTN_3/4/5/6` click
- Pinch:
  - `INPUT_BTN_7` press/release + `REL_WHEEL`
- Relative:
  - 1Fで `REL_X/Y`
  - 2F Scroll/Pinchで `REL_WHEEL/HWHEEL`

## 7. 改訂履歴

- 2026-02-25: 初版ドラフト
- 2026-02-27: 実装追従更新
  - 2F/3F の `release_pending` 記載追加
  - `TAP_MAX_MS` を 1F/2F/3F で明示分離 (`150/150/180`)
  - 高優先パラメータ（Tap時間/移動、Hold最短、2F Scroll開始、2F Pinch開始）を `Kconfig` 化
  - `Kconfig` 管理の一覧を `documents/iqs9151_kconfig_reference.md` へ分割
  - 3F `1->3` / `2->3` lead 許容を記載
  - 現在の閾値 (`SCROLL_START_MOVE=50`, `PINCH_START_DISTANCE=80`) に更新
  - 3F Swipe の1ショット実装を `three_swipe_sent` ラッチ方式に更新
- 2026-02-28: HOLD候補の失効ルールを追記
  - 1F/2F/3F Hold は、Hold移動閾値を一度でも超えた接触では再成立しない仕様に更新
