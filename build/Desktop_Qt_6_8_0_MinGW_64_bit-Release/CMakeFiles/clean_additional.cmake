# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\SUmusic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SUmusic_autogen.dir\\ParseCache.txt"
  "SUmusic_autogen"
  )
endif()
