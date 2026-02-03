zephyr_library()

# ZMK app public headers (e.g. include/drivers/behavior.h)
zephyr_library_include_directories(${ZEPHYR_BASE}/../app/include)
zephyr_library_include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)

zephyr_library_sources_ifdef(CONFIG_ZMK_BEHAVIOR_TRACKPAD_TO_POS behavior_trackpad_to_pos.c)
zephyr_library_sources_ifdef(CONFIG_ZMK_BEHAVIOR_ZIP_DYNAMIC_SCALE behavior_zip_dynamic_scale.c)
