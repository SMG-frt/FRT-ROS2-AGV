#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_402_driver::lifecycle_cia402_driver" for configuration ""
set_property(TARGET canopen_402_driver::lifecycle_cia402_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_402_driver::lifecycle_cia402_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblifecycle_cia402_driver.so"
  IMPORTED_SONAME_NOCONFIG "liblifecycle_cia402_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_402_driver::lifecycle_cia402_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_402_driver::lifecycle_cia402_driver "${_IMPORT_PREFIX}/lib/liblifecycle_cia402_driver.so" )

# Import target "canopen_402_driver::cia402_driver" for configuration ""
set_property(TARGET canopen_402_driver::cia402_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_402_driver::cia402_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcia402_driver.so"
  IMPORTED_SONAME_NOCONFIG "libcia402_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_402_driver::cia402_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_402_driver::cia402_driver "${_IMPORT_PREFIX}/lib/libcia402_driver.so" )

# Import target "canopen_402_driver::node_canopen_cia402_driver" for configuration ""
set_property(TARGET canopen_402_driver::node_canopen_cia402_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_402_driver::node_canopen_cia402_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnode_canopen_cia402_driver.so"
  IMPORTED_SONAME_NOCONFIG "libnode_canopen_cia402_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_402_driver::node_canopen_cia402_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_402_driver::node_canopen_cia402_driver "${_IMPORT_PREFIX}/lib/libnode_canopen_cia402_driver.so" )

# Import target "canopen_402_driver::lely_motion_controller_bridge" for configuration ""
set_property(TARGET canopen_402_driver::lely_motion_controller_bridge APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_402_driver::lely_motion_controller_bridge PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblely_motion_controller_bridge.so"
  IMPORTED_SONAME_NOCONFIG "liblely_motion_controller_bridge.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_402_driver::lely_motion_controller_bridge )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_402_driver::lely_motion_controller_bridge "${_IMPORT_PREFIX}/lib/liblely_motion_controller_bridge.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
