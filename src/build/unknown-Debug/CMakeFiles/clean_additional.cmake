# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/flac-media-converter_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/flac-media-converter_autogen.dir/ParseCache.txt"
  "flac-media-converter_autogen"
  )
endif()
