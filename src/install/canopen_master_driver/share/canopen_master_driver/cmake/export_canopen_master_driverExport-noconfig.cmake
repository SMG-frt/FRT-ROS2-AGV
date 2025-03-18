#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_master_driver::lifecycle_master_driver" for configuration ""
set_property(TARGET canopen_master_driver::lifecycle_master_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_master_driver::lifecycle_master_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblifecycle_master_driver.so"
  IMPORTED_SONAME_NOCONFIG "liblifecycle_master_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_master_driver::lifecycle_master_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_master_driver::lifecycle_master_driver "${_IMPORT_PREFIX}/lib/liblifecycle_master_driver.so" )

# Import target "canopen_master_driver::master_driver" for configuration ""
set_property(TARGET canopen_master_driver::master_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_master_driver::master_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmaster_driver.so"
  IMPORTED_SONAME_NOCONFIG "libmaster_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_master_driver::master_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_master_driver::master_driver "${_IMPORT_PREFIX}/lib/libmaster_driver.so" )

# Import target "canopen_master_driver::node_canopen_basic_master" for configuration ""
set_property(TARGET canopen_master_driver::node_canopen_basic_master APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_master_driver::node_canopen_basic_master PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnode_canopen_basic_master.so"
  IMPORTED_SONAME_NOCONFIG "libnode_canopen_basic_master.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_master_driver::node_canopen_basic_master )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_master_driver::node_canopen_basic_master "${_IMPORT_PREFIX}/lib/libnode_canopen_basic_master.so" )

# Import target "canopen_master_driver::lely_master_bridge" for configuration ""
set_property(TARGET canopen_master_driver::lely_master_bridge APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_master_driver::lely_master_bridge PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblely_master_bridge.so"
  IMPORTED_SONAME_NOCONFIG "liblely_master_bridge.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_master_driver::lely_master_bridge )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_master_driver::lely_master_bridge "${_IMPORT_PREFIX}/lib/liblely_master_bridge.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
