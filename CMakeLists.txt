cmake_minimum_required(VERSION 3.18)

project(ZintZXingCppDemo)

file(COPY deps DESTINATION ${CMAKE_BINARY_DIR})

execute_process(
  COMMAND
    "${CMAKE_COMMAND}"
      -E make_directory build
  WORKING_DIRECTORY
    "${CMAKE_BINARY_DIR}/deps"
)
execute_process(
  COMMAND
    "${CMAKE_COMMAND}"
      -G "${CMAKE_GENERATOR}"
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DBARCODE_LIBS_STATIC=${BARCODE_LIBS_STATIC}
      -DFUZZER_MODE=${FUZZER_MODE}
      -DSANITIZE_MODE=${SANITIZE_MODE}
      -DUPSTREAM_MODE=${UPSTREAM_MODE}
      ..
  WORKING_DIRECTORY
    "${CMAKE_BINARY_DIR}/deps/build"
)
execute_process(
  COMMAND
    "${CMAKE_COMMAND}"
      --build .
      --config ${CMAKE_BUILD_TYPE}
  WORKING_DIRECTORY
    "${CMAKE_BINARY_DIR}/deps/build"
)

add_subdirectory(src)

