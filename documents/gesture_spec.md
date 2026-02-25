# IQS9151 Gesture Specification(Draft)

この文書は、`iqs9151_work_cb()` / `iqs9151_one_finger_update()` / `iqs9151_two_finger_update()` / `iqs9151_three_finger_update()` の仕様を整理するためのドラフト仕様書です。

## 0. 前提

- IC内蔵ジェスチャレジスタ (`0x101C` / `0x101E`) は **使用しない**。
- 判定は `0x1014..0x102E` の座標・フラグを基準に、ドライバ側状態機械で行う。
- 本文書は「実装」と「意図仕様」を一致させるための編集ベース。

## 1. 入力フレーム定義（メモリマップ基準）

|項目|アドレス|ビット/型|意味|利用有無|
| - | - | - | - | - |
|Relative X|`0x1014`|`int16`|相対X移動量|使用|
|Relative Y|`0x1016`|`int16`|相対Y移動量|使用|
|Info Flags|`0x1020`|`uint16`|`SHOW_RESET` 等|使用|
|Trackpad Flags|`0x1022`|`uint16`|`finger_count` / `movement_detected` / confidence|使用|
|Finger1 X/Y|`0x1024`/`0x1026`|`uint16`|1本指座標|使用|
|Finger2 X/Y|`0x102C`/`0x102E`|`uint16`|2本指座標|使用|
|Single Finger Gestures|`0x101C`|`uint16`|IC内蔵1Fジェスチャ|不使用|
|Two-Finger Gestures|`0x101E`|`uint16`|IC内蔵2Fジェスチャ|不使用|

## 2. 正規化ルール（座標有効性）

|ルールID|条件|正規化ルール|備考|
| - | - | - | - |
|N-1|`finger_count == 0`|`prev_frame.finger1/2_x/y = 0`|リリース時リセット|
|N-2|`finger1_confidence == 0` または `f1==0xFFFF`|`finger1` は `prev_frame` の値をフォールバック|`iqs9151_get_finger1_xy()` 想定|
|N-3|`finger_count < 2`|`prev_frame.finger2_x/y = 0`|2本指未満でクリア|
|N-4|`finger2_confidence == 0` または `f2==0xFFFF`|`finger2` は `prev_frame` をフォールバック|`iqs9151_get_finger2_xy()` 想定|
|N-5|`SHOW_RESET` 検出|当該フレームの判定を中止し、全ジェスチャ状態をリセット|イベント出力なし|

## 3. ジェスチャ仕様サマリ（1F/2F/3F）

記載ルール:
- 継続条件: その状態を次フレームでも維持し、内部状態を更新し続ける条件
- 終了条件: 状態を抜ける条件。成立時に出力イベントを実行
- 中断条件: 出力イベント無しで状態を中断し、状態はリセット
- `SHOW_RESET` はフレーム処理冒頭で判定して return するため、以下の各条件式には含めない
- 3Fの移動量は `finger1` 追跡で計算する（中心点は使わない）

時間パラメータ（固定値。後でKconfig化予定）:
- `TAP_MAX_MS = 150`
- `HOLD_MIN_MS = 200`
- `TAP_REENTRY_WINDOW_MS = 30`

|ジェスチャ|開始条件|継続条件|終了条件|中断条件|出力イベント|しきい値/備考|
| - | - | - | - | - | - | - |
|1Fセッション|`finger_count==1`|`finger_count==1`|`finger_count!=1`|なし|なし|`finger1` の `dx/dy` と経過時間を蓄積|
|1F Tap|`finger_count==1` かつ `直近TAP_REENTRY_WINDOW_MS以内にfinger_count==0` かつ `elapsed<=TAP_MAX_MS` かつ `abs(dx)<=ONE_FINGER_TAP_MOVE && abs(dy)<=ONE_FINGER_TAP_MOVE`|finger_count==1 かつ elapsed<=TAP_MAX_MS かつ abs(dx)<=ONE_FINGER_TAP_MOVE && abs(dy)<=ONE_FINGER_TAP_MOVE|`finger_count==0` かつ Tap条件成立|`elapsed>TAP_MAX_MS` または移動量がTap閾値超え|`INPUT_BTN_0` click|1F内優先度は最上位|
|1F Hold|`finger_count==1` かつ `elapsed>=HOLD_MIN_MS` かつ `abs(dx)<=ONE_FINGER_HOLD_MOVE && abs(dy)<=ONE_FINGER_HOLD_MOVE` かつ 1F Tap未成立|Hold active 中は継続|**別Tapまたは別Holdが成立**|なし|`INPUT_BTN_0` press/release|`finger_count` 変化では終了しない|
|1F Rel|`finger_count==1` かつ 1F Tap/1F Hold の開始条件が未成立 かつ `max(abs(dx),abs(dy))>ONE_FINGER_TAP_MOVE`|`finger_count==1` かつ 1F Tap/1F Hold未成立|`finger_count!=1`|なし|`INPUT_REL_X/Y`|1F内優先度は Tap > Hold > Rel|
|2Fセッション|`finger_count==2`|`finger_count==2`|`finger_count!=2`|なし|なし|中心点移動量・指間距離・経過時間を蓄積|
|2F Tap|`finger_count==2` かつ `直近TAP_REENTRY_WINDOW_MS以内にfinger_count==0` かつ `elapsed<=TAP_MAX_MS` かつ `abs(centroid_dx)<=TWO_FINGER_TAP_MOVE && abs(centroid_dy)<=TWO_FINGER_TAP_MOVE && abs(distance_delta)<=TWO_FINGER_TAP_MOVE`|開始条件を満たす間継続|`finger_count==0` かつ Tap条件成立|2F Scroll/2F Pinch確定、またはHold開始条件成立|`INPUT_BTN_1` click|履歴参照は `finger_count` のみ|
|2F Hold|`finger_count==2` かつ `mode==NONE` かつ `elapsed>=HOLD_MIN_MS` かつ `abs(centroid_dx)<=TWO_FINGER_HOLD_MOVE && abs(centroid_dy)<=TWO_FINGER_HOLD_MOVE && abs(distance_delta)<=TWO_FINGER_HOLD_MOVE` かつ 2F Tap未成立|Hold active 中は継続|**別Tapまたは別Holdが成立**|2F Scroll/2F Pinch確定|`INPUT_BTN_1` press/release|`finger_count` 変化では終了しない|
|2F Scroll|`finger_count==2` かつ `mode==NONE` かつ `max(abs(centroid_dx),abs(centroid_dy))>=TWO_FINGER_SCROLL_START_MOVE`|`finger_count==2` かつ `mode==SCROLL`|`finger_count!=2`|なし|`REL_WHEEL/HWHEEL`|Pinchと排他。同時成立時はScroll優先でmode固定|
|2F Pinch|`finger_count==2` かつ `mode==NONE` かつ `abs(distance_delta)>=TWO_FINGER_PINCH_START_DISTANCE` かつ `abs(distance_delta)>max(abs(centroid_dx),abs(centroid_dy))` かつ Scroll開始条件が未成立|`finger_count==2` かつ `mode==PINCH`|`finger_count!=2`|なし|`INPUT_BTN_7` press/release + `REL_WHEEL`|Scrollと排他。mode固定|
|3Fセッション|`finger_count==3`|`finger_count==3`|`finger_count!=3`|なし|なし|`finger1` の `dx/dy` と経過時間を蓄積|
|3F Tap|`finger_count==3` かつ `直近TAP_REENTRY_WINDOW_MS以内にfinger_count==0` かつ `elapsed<=TAP_MAX_MS` かつ `abs(dx)<=THREE_FINGER_TAP_MOVE && abs(dy)<=THREE_FINGER_TAP_MOVE`|開始条件を満たす間継続|`finger_count==0` かつ Tap条件成立|3F Swipe確定、または3F Hold開始条件成立|`INPUT_BTN_2` click|履歴参照は `finger_count` のみ|
|3F Hold|`finger_count==3` かつ `elapsed>=HOLD_MIN_MS` かつ `abs(dx)<=THREE_FINGER_HOLD_MOVE && abs(dy)<=THREE_FINGER_HOLD_MOVE` かつ 3F Tap未成立|Hold active 中は継続|**別Tapまたは別Holdが成立**|なし|`INPUT_BTN_2` press/release|`finger_count` 変化では終了しない。Swipeと同時成立時はHold優先|
|3F Swipe|`finger_count==3` かつ (`abs(dx)>=CONFIG_INPUT_IQS9151_3F_SWIPE_THRESHOLD && abs(dx)>=abs(dy)` または `abs(dy)>=CONFIG_INPUT_IQS9151_3F_SWIPE_THRESHOLD && abs(dy)>abs(dx)`) かつ 3F Hold開始条件が未成立|継続なし（1ショット）|成立フレームで即終了|なし|左右: `BTN_3/4`、上下: `BTN_5/6` click|成立後は3Fセッションを即リセット|

## 4. 優先度・排他・中断

|項目|仕様|
| - | - |
|本数別セッション|1フレームで処理する基底セッションは `finger_count` に対応する1種類のみ（1F/2F/3F）|
|同一セッション内優先度|`Tap > Hold > Rel`|
|1F Tap再エントリ|1F Tapも `TAP_REENTRY_WINDOW_MS` 内の `finger_count==0` 観測を開始条件に含める|
|2F Scroll/Pinch競合|同時成立時はScroll優先。確定後は排他ロック（終了までモード固定）|
|Holdの単一性|`hold_button` は単一。別Tap/Hold成立条件を検出したフレームでは現Holdをreleaseし、新規Tap/Holdイベントは出力しない|
|Hold継続|Holdは「別Tapまたは別Hold成立」まで継続する|
|3F Hold/Swipe競合|同時成立時はHold優先|
|中断時の状態|中断時は状態を必ずリセット|
|SHOW_RESET処理位置|`work_cb` 冒頭のガードで検出し、全ジェスチャ状態をリセットして return（後続条件分岐では参照しない）|

## 5. 時間窓・履歴参照

|項目|仕様|
| - | - |
|共通時間閾値|`TAP_MAX_MS=150` / `HOLD_MIN_MS=200` / `TAP_REENTRY_WINDOW_MS=30`|
|履歴参照単位|フレーム数ではなく ms で判定する|
|履歴内容|Tap判定の履歴参照は `finger_count` のみ（confidence/座標は参照しない）|
|履歴バッファ|内部実装は最大5フレーム程度を想定（約50ms @10ms周期）|
|2F/3F再エントリ|`2->1->2` などチャタリング遷移は `TAP_REENTRY_WINDOW_MS` 内ならTap候補に含める|
|移動量閾値|既存定義値を流用（`ONE_FINGER_*` / `TWO_FINGER_*` / `THREE_FINGER_*`）|

## 6. 出力イベント仕様（ZMK Input）

|種別|イベント|トリガ|補足|
| - | - | - | - |
|Click|`INPUT_BTN_0`|1F Tap|press+release|
|Click|`INPUT_BTN_1`|2F Tap|press+release|
|Click|`INPUT_BTN_2`|3F Tap|press+release|
|Hold|`INPUT_BTN_0`|1F Hold|`hold_button` 管理対象|
|Hold|`INPUT_BTN_1`|2F Hold|`hold_button` 管理対象|
|Hold|`INPUT_BTN_2`|3F Hold|`hold_button` 管理対象|
|Swipe|`INPUT_BTN_3/4/5/6`|3F Swipe|方向別1ショット|
|Pinch mode key|`INPUT_BTN_7`|2F Pinch開始/終了|状態同期キー|
|Relative cursor|`INPUT_REL_X/Y`|1F Rel|Tap/Hold非成立時のみ|
|Relative scroll|`INPUT_REL_WHEEL/HWHEEL`|2F Scroll/Pinch|PinchはWHEEL使用|
|Inertia cursor|`INPUT_REL_X/Y` 継続|1F Rel終了時|Hold成立時は開始しない|
|Inertia scroll|`INPUT_REL_WHEEL/HWHEEL` 継続|2F Scroll終了時|Pinchへの遷移では開始しない|

## 7. 未決定項目（編集用）

|ID|論点|候補/メモ|決定値|
| - | - | - | - |
|D-1|Tap/Holdの閾値管理|現時点は固定値、最終的にKconfig化|`FIXED -> Kconfig`|
|D-2|履歴管理実装|`prev_frame` 単体から時刻付きリングバッファへ拡張（最大5フレーム想定）|`[TBD]`|

## 8. 改訂履歴

- 2026-02-25: 初版雛形作成
- 2026-02-25: ユーザー回答反映（Tap>Hold>Rel、2F排他、ms窓、SHOW_RESET全リセット）
- 2026-02-25: 条件式を具体化、時間閾値を確定（150/200/30）、Hold終了条件とSHOW_RESET記載方針を修正
- 2026-02-25: 追加確定（1F再エントリ適用、Hold継続ルール、3F Hold優先）
