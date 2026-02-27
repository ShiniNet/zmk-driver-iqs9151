#include <zephyr/input/input.h>
#include <zephyr/ztest.h>

#include "iqs9151_regs.h"
#include "iqs9151_test.h"

#include <string.h>

#define IQS9151_TEST_CTX_BUF_SIZE 1024
#define IQS9151_TEST_MAX_EVENTS 32

struct event_log {
    struct iqs9151_test_event events[IQS9151_TEST_MAX_EVENTS];
    size_t count;
};

struct iqs9151_work_cb_fixture {
    uint8_t ctx[IQS9151_TEST_CTX_BUF_SIZE];
    struct event_log log;
};

int input_report(const struct device *dev,
                 uint8_t type, uint16_t code, int32_t value, bool sync,
                 k_timeout_t timeout) {
    ARG_UNUSED(dev);
    ARG_UNUSED(type);
    ARG_UNUSED(code);
    ARG_UNUSED(value);
    ARG_UNUSED(sync);
    ARG_UNUSED(timeout);
    return 0;
}

static void record_event(const struct iqs9151_test_event *event, void *user_data) {
    struct event_log *log = (struct event_log *)user_data;

    if (log->count >= IQS9151_TEST_MAX_EVENTS) {
        return;
    }

    log->events[log->count++] = *event;
}

static struct iqs9151_test_frame make_frame(uint8_t finger_count,
                                            uint16_t trackpad_flags,
                                            int16_t rel_x, int16_t rel_y,
                                            uint16_t info_flags,
                                            uint16_t finger1_x, uint16_t finger1_y,
                                            uint16_t finger2_x, uint16_t finger2_y) {
    return (struct iqs9151_test_frame){
        .rel_x = rel_x,
        .rel_y = rel_y,
        .info_flags = info_flags,
        .trackpad_flags = trackpad_flags,
        .finger_count = finger_count,
        .finger1_x = finger1_x,
        .finger1_y = finger1_y,
        .finger2_x = finger2_x,
        .finger2_y = finger2_y,
    };
}

static void *iqs9151_work_cb_setup(void) {
    static struct iqs9151_work_cb_fixture fixture;
    const size_t ctx_size = iqs9151_test_context_size();

    zassert_true(ctx_size <= sizeof(fixture.ctx),
                 "Context buffer too small: %u > %u",
                 (unsigned int)ctx_size,
                 (unsigned int)sizeof(fixture.ctx));
    memset(&fixture, 0, sizeof(fixture));
    iqs9151_test_context_init(fixture.ctx, NULL);
    iqs9151_test_set_event_hook(record_event, &fixture.log);
    return &fixture;
}

static void iqs9151_work_cb_before(void *fixture_ptr) {
    struct iqs9151_work_cb_fixture *fixture =
        (struct iqs9151_work_cb_fixture *)fixture_ptr;

    memset(&fixture->log, 0, sizeof(fixture->log));
    iqs9151_test_context_init(fixture->ctx, NULL);
    iqs9151_test_set_event_hook(record_event, &fixture->log);
}

ZTEST_F(iqs9151_work_cb, test_show_reset_releases_pinch_and_clears_state) {
    const struct iqs9151_test_frame show_reset_frame =
        make_frame(2U, 2U, 0, 0, IQS9151_INFO_SHOW_RESET, 0, 0, 0, 0);

    iqs9151_test_force_pinch_session(fixture->ctx, true);
    iqs9151_test_process_frame(fixture->ctx, &show_reset_frame, 10);

    zassert_equal(fixture->log.count, 1U, "Unexpected event count");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Not a key event");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_7, "Unexpected key code");
    zassert_equal(fixture->log.events[0].value, 0, "Expected pinch release");
    zassert_false(iqs9151_test_scroll_inertia_active(fixture->ctx),
                  "Scroll inertia should be inactive");
    zassert_false(iqs9151_test_cursor_inertia_active(fixture->ctx),
                  "Cursor inertia should be inactive");
    zassert_equal(iqs9151_test_prev_finger_count(fixture->ctx), 0U,
                  "Previous frame should be reset");
    zassert_equal(iqs9151_test_hold_button(fixture->ctx), 0U,
                  "Hold button should be cleared");
}

ZTEST_F(iqs9151_work_cb, test_one_finger_release_starts_cursor_inertia) {
    const struct iqs9151_test_frame one_start =
        make_frame(1U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_MOVEMENT_DETECTED | 1U,
                   24, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame one_move =
        make_frame(1U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_MOVEMENT_DETECTED | 1U,
                   20, 0, 0, 140, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_start, 0);
    iqs9151_test_process_frame(fixture->ctx, &one_move, 10);
    iqs9151_test_process_frame(fixture->ctx, &release, 20);

    zassert_true(iqs9151_test_cursor_inertia_active(fixture->ctx),
                 "Cursor inertia should start on release");
    zassert_equal(iqs9151_test_prev_finger_count(fixture->ctx), 0U,
                  "Previous frame should track release");
    zassert_equal(fixture->log.count, 4U,
                  "Only REL events from movement frames are expected");
    for (size_t i = 0; i < fixture->log.count; i++) {
        zassert_equal(fixture->log.events[i].type, IQS9151_TEST_EVENT_REL,
                      "Unexpected non-REL event at idx %u", (unsigned int)i);
    }
}

ZTEST_F(iqs9151_work_cb, test_two_finger_scroll_reports_and_starts_scroll_inertia) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame two_scroll =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 160, 100, 260, 100);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_start, 0);
    iqs9151_test_process_frame(fixture->ctx, &two_scroll, 10);
    iqs9151_test_process_frame(fixture->ctx, &release, 20);

    zassert_true(iqs9151_test_scroll_inertia_active(fixture->ctx),
                 "Scroll inertia should start on 2F scroll release");
    zassert_equal(iqs9151_test_prev_finger_count(fixture->ctx), 0U,
                  "Previous frame should track release");
    zassert_equal(fixture->log.count, 1U,
                  "Expected a single horizontal wheel event during scroll");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_REL, "Not a REL event");
    zassert_equal(fixture->log.events[0].code, INPUT_REL_HWHEEL, "Unexpected REL code");
    zassert_equal(fixture->log.events[0].value, -60, "Unexpected HWHEEL delta");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_pinch_reports_btn7_and_wheel) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame two_pinch =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 60, 100, 240, 100);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_start, 0);
    iqs9151_test_process_frame(fixture->ctx, &two_pinch, 10);
    iqs9151_test_process_frame(fixture->ctx, &release, 20);

    zassert_equal(fixture->log.count, 3U, "Expected BTN7 press, wheel, BTN7 release");

    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_7, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN7 press");

    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_REL, "Event[1] not rel");
    zassert_equal(fixture->log.events[1].code, INPUT_REL_WHEEL, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 6, "Event[1] unexpected wheel value");

    zassert_equal(fixture->log.events[2].type, IQS9151_TEST_EVENT_KEY, "Event[2] not key");
    zassert_equal(fixture->log.events[2].code, INPUT_BTN_7, "Event[2] unexpected code");
    zassert_equal(fixture->log.events[2].value, 0, "Event[2] should be BTN7 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_pinch_to_three_finger_releases_btn7) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame two_pinch =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 60, 100, 240, 100);
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 100, 100, 200, 100);

    iqs9151_test_process_frame(fixture->ctx, &two_start, 0);
    iqs9151_test_process_frame(fixture->ctx, &two_pinch, 10);
    iqs9151_test_process_frame(fixture->ctx, &three_start, 20);

    zassert_equal(fixture->log.count, 3U,
                  "Expected BTN7 press, wheel, BTN7 release on 2F->3F transition");
    zassert_equal(fixture->log.events[2].type, IQS9151_TEST_EVENT_KEY, "Event[2] not key");
    zassert_equal(fixture->log.events[2].code, INPUT_BTN_7, "Event[2] unexpected code");
    zassert_equal(fixture->log.events[2].value, 0, "Event[2] should be BTN7 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_click_emits_btn1) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN1 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_1, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN1 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_1, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN1 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_staggered_release_emits_btn1) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN1 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_1, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN1 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_1, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN1 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_one_lead_finger_emits_btn1) {
    const struct iqs9151_test_frame one_lead =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN1 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_1, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN1 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_1, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN1 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_moved_one_lead_does_not_click) {
    const struct iqs9151_test_frame one_lead =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame one_lead_move =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 140, 100, 0, 0);
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 140, 100, 240, 100);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 140, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_lead_move, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 0U, "Moved one-finger lead should not become 2F tap");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_jitter_no_pinch_emits_btn1) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 2230, 1577, 622, 2198);
    const struct iqs9151_test_frame two_jitter =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 2217, 1580, 630, 2198);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 2217, 1580, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_jitter, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN1 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_1, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN1 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_1, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN1 release");
}

ZTEST_F(iqs9151_work_cb, test_two_finger_tap_releases_latched_hold) {
    const struct iqs9151_test_frame two_start =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 100, 100, 200, 100);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_force_hold_button(fixture->ctx, INPUT_BTN_1);

    iqs9151_test_process_frame(fixture->ctx, &two_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 1U,
                  "Expected BTN1 release by 2F tap when hold is latched");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_1, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 0, "Event[0] should be BTN1 release");
    zassert_equal(iqs9151_test_hold_button(fixture->ctx), 0U,
                  "Hold button should be cleared by 2F tap");
}

ZTEST_F(iqs9151_work_cb, test_one_finger_hold_prevents_cursor_inertia_start) {
    const struct iqs9151_test_frame one_down =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame one_hold_check =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_down, k_uptime_get());
    k_msleep(220);
    iqs9151_test_process_frame(fixture->ctx, &one_hold_check, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 1U, "Expected only BTN0 hold press");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_0, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN0 press");
    zassert_false(iqs9151_test_cursor_inertia_active(fixture->ctx),
                  "Cursor inertia should not start after hold release");
    zassert_equal(iqs9151_test_hold_button(fixture->ctx), INPUT_BTN_0,
                  "Hold button should stay latched until another hold/tap");
}

ZTEST_F(iqs9151_work_cb, test_one_finger_tap_releases_latched_hold) {
    const struct iqs9151_test_frame tap_down =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 100, 100, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_force_hold_button(fixture->ctx, INPUT_BTN_0);

    iqs9151_test_process_frame(fixture->ctx, &tap_down, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 1U,
                  "Expected BTN0 release by tap when hold is latched");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_0, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 0, "Event[0] should be BTN0 release");
    zassert_equal(iqs9151_test_hold_button(fixture->ctx), 0U,
                  "Hold button should be cleared by tap");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_releases_latched_hold) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_force_hold_button(fixture->ctx, INPUT_BTN_2);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 1U,
                  "Expected BTN2 release by 3F tap when hold is latched");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 0, "Event[0] should be BTN2 release");
    zassert_equal(iqs9151_test_hold_button(fixture->ctx), 0U,
                  "Hold button should be cleared by 3F tap");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_click_emits_btn2) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN2 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN2 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_2, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN2 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_staggered_release_emits_btn2) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame two_release =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 500, 500, 620, 500);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN2 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN2 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_2, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN2 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_one_lead_finger_emits_btn2) {
    const struct iqs9151_test_frame one_lead =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN2 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN2 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_2, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN2 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_moved_one_lead_does_not_click) {
    const struct iqs9151_test_frame one_lead =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame one_lead_move =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 540, 500, 0, 0);
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 540, 500, 0, 0);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 540, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &one_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_lead_move, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 0U, "Moved one-finger lead should not become 3F tap");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_two_lead_fingers_emits_btn2) {
    const struct iqs9151_test_frame two_lead =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 500, 500, 620, 500);
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame two_release =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 500, 500, 620, 500);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN2 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN2 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_2, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN2 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_moved_two_lead_does_not_click) {
    const struct iqs9151_test_frame two_lead =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 500, 500, 620, 500);
    const struct iqs9151_test_frame two_lead_move =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 540, 500, 660, 500);
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 540, 500, 0, 0);
    const struct iqs9151_test_frame two_release =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 540, 500, 660, 500);
    const struct iqs9151_test_frame one_release =
        make_frame(1U, IQS9151_TP_FINGER1_CONFIDENCE | 1U, 0, 0, 0, 540, 500, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &two_lead, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_lead_move, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &one_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 0U, "Moved two-finger lead should not become 3F tap");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_tap_step_to_two_then_zero_avoids_btn1) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 500, 500, 0, 0);
    const struct iqs9151_test_frame two_release =
        make_frame(2U,
                   IQS9151_TP_FINGER1_CONFIDENCE | IQS9151_TP_FINGER2_CONFIDENCE | 2U,
                   0, 0, 0, 500, 500, 620, 500);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &two_release, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN2 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_2, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN2 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_2, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN2 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_swipe_right_emits_btn3_click) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1000, 1000, 0, 0);
    const struct iqs9151_test_frame three_swipe =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1400, 1000, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &three_swipe, k_uptime_get());

    zassert_equal(fixture->log.count, 2U, "Expected BTN3 click (press + release)");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_3, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN3 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_3, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN3 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_swipe_continuous_touch_emits_once) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1000, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_1 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1400, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_2 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1800, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_3 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 2200, 1000, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_1, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_2, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_3, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U,
                  "Expected a single BTN3 click while 3 fingers stay on pad");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_3, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN3 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_3, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN3 release");
}

ZTEST_F(iqs9151_work_cb, test_three_finger_swipe_left_continuous_touch_emits_once) {
    const struct iqs9151_test_frame three_start =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 2200, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_1 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1800, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_2 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1400, 1000, 0, 0);
    const struct iqs9151_test_frame swipe_step_3 =
        make_frame(3U, IQS9151_TP_FINGER1_CONFIDENCE | 3U, 0, 0, 0, 1000, 1000, 0, 0);
    const struct iqs9151_test_frame release =
        make_frame(0U, 0U, 0, 0, 0, 0, 0, 0, 0);

    iqs9151_test_process_frame(fixture->ctx, &three_start, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_1, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_2, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &swipe_step_3, k_uptime_get());
    iqs9151_test_process_frame(fixture->ctx, &release, k_uptime_get());

    zassert_equal(fixture->log.count, 2U,
                  "Expected a single BTN4 click while 3 fingers stay on pad");
    zassert_equal(fixture->log.events[0].type, IQS9151_TEST_EVENT_KEY, "Event[0] not key");
    zassert_equal(fixture->log.events[0].code, INPUT_BTN_4, "Event[0] unexpected code");
    zassert_equal(fixture->log.events[0].value, 1, "Event[0] should be BTN4 press");
    zassert_equal(fixture->log.events[1].type, IQS9151_TEST_EVENT_KEY, "Event[1] not key");
    zassert_equal(fixture->log.events[1].code, INPUT_BTN_4, "Event[1] unexpected code");
    zassert_equal(fixture->log.events[1].value, 0, "Event[1] should be BTN4 release");
}

ZTEST_SUITE(iqs9151_work_cb, NULL, iqs9151_work_cb_setup, iqs9151_work_cb_before, NULL, NULL);
