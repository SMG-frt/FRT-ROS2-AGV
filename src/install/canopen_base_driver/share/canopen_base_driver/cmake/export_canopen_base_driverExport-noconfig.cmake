#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_base_driver::lifecycle_base_driver" for configuration ""
set_property(TARGET canopen_base_driver::lifecycle_base_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_base_driver::lifecycle_base_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblifecycle_base_driver.so"
  IMPORTED_SONAME_NOCONFIG "liblifecycle_base_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_base_driver::lifecycle_base_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_base_driver::lifecycle_base_driver "${_IMPORT_PREFIX}/lib/liblifecycle_base_driver.so" )

# Import target "canopen_base_driver::base_driver" for configuration ""
set_property(TARGET canopen_base_driver::base_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_base_driver::base_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libbase_driver.so"
  IMPORTED_SONAME_NOCONFIG "libbase_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_base_driver::base_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_base_driver::base_driver "${_IMPORT_PREFIX}/lib/libbase_driver.so" )

# Import target "canopen_base_driver::node_canopen_base_driver" for configuration ""
set_property(TARGET canopen_base_driver::node_canopen_base_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_base_driver::node_canopen_base_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnode_canopen_base_driver.so"
  IMPORTED_SONAME_NOCONFIG "libnode_canopen_base_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_base_driver::node_canopen_base_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_base_driver::node_canopen_base_driver "${_IMPORT_PREFIX}/lib/libnode_canopen_base_driver.so" )

# Import target "canopen_base_driver::lely_driver_bridge" for configuration ""
set_property(TARGET canopen_base_driver::lely_driver_bridge APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_base_driver::lely_driver_bridge PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblely_driver_bridge.so"
  IMPORTED_SONAME_NOCONFIG "liblely_driver_bridge.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_base_driver::lely_driver_bridge )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_base_driver::lely_driver_bridge "${_IMPORT_PREFIX}/lib/liblely_driver_bridge.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
