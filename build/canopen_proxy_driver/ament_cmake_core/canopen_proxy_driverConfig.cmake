# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_canopen_proxy_driver_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED canopen_proxy_driver_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(canopen_proxy_driver_FOUND FALSE)
  elseif(NOT canopen_proxy_driver_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(canopen_proxy_driver_FOUND FALSE)
  endif()
  return()
endif()
set(_canopen_proxy_driver_CONFIG_INCLUDED TRUE)

# output package information
if(NOT canopen_proxy_driver_FIND_QUIETLY)
  message(STATUS "Found canopen_proxy_driver: 0.2.11 (${canopen_proxy_driver_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'canopen_proxy_driver' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${canopen_proxy_driver_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(canopen_proxy_driver_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${canopen_proxy_driver_DIR}/${_extra}")
endforeach()
