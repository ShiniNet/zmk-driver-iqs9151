# IQS9151 `work_cb` ZTESTケース一覧（実装同期版）

この文書は `tests/iqs9151_work_cb/src/main.c` の現行ケースを
レビューしやすい一覧にしたものです。

## 前提

- 実行環境: `native_sim_64`（`native_sim` でも実行可能）
- テストフック: `CONFIG_INPUT_IQS9151_TEST=y`
- 観測対象:
  - 出力イベント (`KEY` / `REL`)
  - 内部状態 (`prev_finger_count`, inertia active, hold_button)

## 閾値（テスト前提）

- 共通:
  - `IQS9151_TAP_REENTRY_WINDOW_MS = 30`
- 1F:
  - `ONE_FINGER_TAP_MAX_MS = 120`
  - `ONE_FINGER_TAP_MOVE = 25`
  - `ONE_FINGER_TAPDRAG_GAP_MAX_MS = 230`
- 2F:
  - `TWO_FINGER_TAP_MAX_MS = 130`
  - `TWO_FINGER_TAP_MOVE = 30`
  - `TWO_FINGER_TAPDRAG_GAP_MAX_MS = 200`
  - `TWO_FINGER_SCROLL_START_MOVE = 50`
  - `TWO_FINGER_PINCH_START_DISTANCE = 80`
  - `TWO_FINGER_PINCH_WHEEL_DIV = 12`
- 3F:
  - `THREE_FINGER_TAP_MAX_MS = 180`
  - `THREE_FINGER_TAP_MOVE = 30`
  - `THREE_FINGER_TAPDRAG_GAP_MAX_MS = 230`
  - `THREE_FINGER_*_LEAD_MAX_MS = 120`
  - `THREE_FINGER_RELEASE_PENDING_MAX_MS = 150`

## ケース一覧（33件）

|No.|テスト名|主な確認点|
| - | - | - |
|1|`test_show_reset_releases_pinch_and_clears_state`|`SHOW_RESET` で BTN7 release と内部状態クリア|
|2|`test_one_finger_release_starts_cursor_inertia`|1Fリリースで cursor inertia 開始|
|3|`test_two_finger_scroll_reports_and_starts_scroll_inertia`|2Fスクロール出力 (`INPUT_REL_HWHEEL=-60`) と scroll inertia|
|4|`test_two_finger_pinch_reports_btn7_and_wheel`|2Fピンチで BTN7 press/wheel/release (`wheel=6`)|
|5|`test_two_finger_pinch_to_three_finger_releases_btn7`|2F pinch中 `2->3` 遷移で BTN7 release|
|6|`test_two_finger_tap_click_emits_btn1`|2Fタップで BTN1 click|
|7|`test_two_finger_tap_staggered_release_emits_btn1`|`2->1->0` 段階リリースで BTN1 click|
|8|`test_two_finger_tap_one_lead_finger_emits_btn1`|`1->2` one-lead で BTN1 click|
|9|`test_two_finger_tap_moved_one_lead_does_not_click`|移動済み one-lead は2Fタップ不成立|
|10|`test_two_finger_tap_jitter_no_pinch_emits_btn1`|軽微ジッターで2Fタップ成立（Pinch誤判定なし）|
|11|`test_two_finger_tap_releases_latched_hold`|2Fタップ時に既存 hold を解放|
|12|`test_one_finger_tap_defers_release_until_timeout`|1F TapでBTN0をpress保持し、timeoutでrelease|
|13|`test_one_finger_double_tap_emits_release_then_click`|1Fダブルタップで「1回目release + 2回目click」を出力|
|14|`test_one_finger_second_touch_drag_releases_on_finger_up`|2回目タッチ継続時はBTN0を保持し、UPでrelease|
|15|`test_one_finger_long_press_without_tapdrag_arm_does_not_emit_hold`|1回目タップ不成立の長押しはBTN0イベントなし|
|16|`test_one_finger_tap_releases_latched_hold`|1Fタップ時に既存 hold を解放|
|17|`test_two_finger_double_tap_emits_release_then_click`|2Fダブルタップで「1回目release + 2回目click」を出力|
|18|`test_two_finger_double_tap_one_lead_second_touch_emits_release_then_click`|2Fダブルタップの2回目 `0->1->2` one-lead でも「1回目release + 2回目click」|
|19|`test_two_finger_second_touch_drag_releases_on_finger_up`|2Fの2回目タッチ継続時はBTN1を保持し、全指UPでrelease|
|20|`test_two_finger_second_touch_drag_one_lead_keeps_hold_until_finger_up`|2F TapDragの2回目 `0->1->2` one-lead でも保持継続し、全指UPでrelease|
|21|`test_three_finger_tap_releases_latched_hold`|3Fタップ時に既存 hold を解放|
|22|`test_three_finger_double_tap_emits_release_then_click`|3Fダブルタップで「1回目release + 2回目click」を出力|
|23|`test_three_finger_second_touch_drag_releases_on_finger_up`|3Fの2回目タッチ継続時はBTN2を保持し、全指UPでrelease|
|24|`test_three_finger_tap_click_emits_btn2`|3Fタップで deferred press後にtimeout release|
|25|`test_three_finger_tap_staggered_release_emits_btn2`|`3->2->1->0` の3Fタップでも deferred press後にtimeout release|
|26|`test_three_finger_tap_one_lead_finger_emits_btn2`|`1->3` one-lead で deferred press後にtimeout release|
|27|`test_three_finger_tap_moved_one_lead_does_not_click`|移動済み one-lead は3Fタップ不成立|
|28|`test_three_finger_tap_two_lead_fingers_emits_btn2`|`2->3` two-lead で deferred press後にtimeout release|
|29|`test_three_finger_tap_moved_two_lead_does_not_click`|移動済み two-lead は3Fタップ不成立|
|30|`test_three_finger_tap_step_to_two_then_zero_avoids_btn1`|`3->2->0` で BTN2成立し BTN1誤発火なし|
|31|`test_three_finger_swipe_right_emits_btn3_click`|3F右スワイプで BTN3 click|
|32|`test_three_finger_swipe_continuous_touch_emits_once`|3F連続接触中のスワイプが1ショットのみ|
|33|`test_three_finger_swipe_left_continuous_touch_emits_once`|3F左スワイプでも連続接触中は1ショットのみ|

注: テスト総数は `33` 件です（2026-03-05 時点）。

## 補足

- 2F/3F Tap は `release_pending` により段階リリース (`2->1->0`, `3->2->1->0`, `3->2->0`) を許容。
- 3F Tap は `1->3` / `2->3` の lead 遷移を許容。
- 3F Swipe は `three_swipe_sent` ラッチで1ショット化し、
  3本指接触が続く間は再送しない。
- 各ケース開始前に `iqs9151_test_cancel_pending_work()` を呼び、
  前ケース由来の `k_work_delayable` をキャンセルして順序依存を防止する。
- 1Fは deferred-click 方式: 1回目TapでBTN0 press保持、2回目Touch判定またはtimeoutでrelease。
- 2F/3Fも deferred-click 方式: 1回目TapでBTN1/BTN2 press保持、2回目Touch判定またはtimeoutでrelease。
- 2F/3F の `*_HOLD_MIN_MS` は互換項目で、現行判定では未使用。

## 実行コマンド

```bash
cd zmk
west build -p -b native_sim_64 ../ShiniNet/zmk-driver-iqs9151/tests/iqs9151_work_cb -d ../artifacts/iqs9151_work_cb_test
west build -d ../artifacts/iqs9151_work_cb_test -t run
```
