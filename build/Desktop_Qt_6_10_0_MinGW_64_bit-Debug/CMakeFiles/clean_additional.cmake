# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Backtester_autogen"
  "CMakeFiles\\Backtester_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Backtester_autogen.dir\\ParseCache.txt"
  )
endif()
