
if(NOT "/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitinfo.txt" IS_NEWER_THAN "/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/ub2004/ros2_ws/build/lely_core_libraries/upstream"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/ub2004/ros2_ws/build/lely_core_libraries/upstream'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://gitlab.com/lely_industries/lely-core.git" "upstream"
    WORKING_DIRECTORY "/home/ub2004/ros2_ws/build/lely_core_libraries"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://gitlab.com/lely_industries/lely-core.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout b63a0b6f79d3ea91dc221724b42dae49894449fc --
  WORKING_DIRECTORY "/home/ub2004/ros2_ws/build/lely_core_libraries/upstream"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'b63a0b6f79d3ea91dc221724b42dae49894449fc'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/ub2004/ros2_ws/build/lely_core_libraries/upstream"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/ub2004/ros2_ws/build/lely_core_libraries/upstream'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitinfo.txt"
    "/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/ub2004/ros2_ws/build/lely_core_libraries/upstr_lely_core_libraries-prefix/src/upstr_lely_core_libraries-stamp/upstr_lely_core_libraries-gitclone-lastrun.txt'")
endif()

