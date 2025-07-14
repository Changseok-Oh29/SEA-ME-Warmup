# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Module3_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Module3_autogen.dir/ParseCache.txt"
  "Module3_autogen"
  )
endif()
