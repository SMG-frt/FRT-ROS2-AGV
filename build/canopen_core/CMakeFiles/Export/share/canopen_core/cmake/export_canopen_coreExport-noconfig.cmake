#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_core::node_canopen_driver" for configuration ""
set_property(TARGET canopen_core::node_canopen_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_core::node_canopen_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnode_canopen_driver.so"
  IMPORTED_SONAME_NOCONFIG "libnode_canopen_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_core::node_canopen_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_core::node_canopen_driver "${_IMPORT_PREFIX}/lib/libnode_canopen_driver.so" )

# Import target "canopen_core::node_canopen_master" for configuration ""
set_property(TARGET canopen_core::node_canopen_master APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_core::node_canopen_master PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libnode_canopen_master.so"
  IMPORTED_SONAME_NOCONFIG "libnode_canopen_master.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_core::node_canopen_master )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_core::node_canopen_master "${_IMPORT_PREFIX}/lib/libnode_canopen_master.so" )

# Import target "canopen_core::device_container" for configuration ""
set_property(TARGET canopen_core::device_container APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_core::device_container PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdevice_container.so"
  IMPORTED_SONAME_NOCONFIG "libdevice_container.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_core::device_container )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_core::device_container "${_IMPORT_PREFIX}/lib/libdevice_container.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
