# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lely_core_libraries_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lely_core_libraries_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lely_core_libraries_FOUND FALSE)
  elseif(NOT lely_core_libraries_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lely_core_libraries_FOUND FALSE)
  endif()
  return()
endif()
set(_lely_core_libraries_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lely_core_libraries_FIND_QUIETLY)
  message(STATUS "Found lely_core_libraries: 0.2.11 (${lely_core_libraries_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lely_core_libraries' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lely_core_libraries_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lely_core_libraries_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "lely_core_libraries-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${lely_core_libraries_DIR}/${_extra}")
endforeach()
