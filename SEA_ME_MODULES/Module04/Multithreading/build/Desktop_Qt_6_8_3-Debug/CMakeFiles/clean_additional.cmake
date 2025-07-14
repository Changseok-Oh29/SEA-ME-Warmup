# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Module4_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Module4_autogen.dir/ParseCache.txt"
  "Module4_autogen"
  )
endif()
