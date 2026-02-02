zephyr_library()

# ZMK app public headers (e.g. include/drivers/behavior.h)
zephyr_library_include_directories(${ZEPHYR_BASE}/../app/include)

zephyr_library_sources_ifdef(CONFIG_ZMK_BEHAVIOR_TRACKPAD_TO_POS behavior_trackpad_to_pos.c)
