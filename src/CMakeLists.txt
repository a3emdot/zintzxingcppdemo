cmake_minimum_required(VERSION 3.18)

project(zintzxingcppdemo-test)

file(GLOB PRO_SRCS
      "*.h"
      "*.cpp")

add_executable(zintzxingcppdemo-test ${PRO_SRCS})

if(FUZZER_MODE)
  target_compile_options(
    zintzxingcppdemo-test
  PRIVATE
    -DFUZZER_MODE -fsanitize=fuzzer,address
  )
  target_link_options(
    zintzxingcppdemo-test
  PRIVATE
    -fsanitize=fuzzer,address
  )
endif(FUZZER_MODE)

target_include_directories(
  zintzxingcppdemo-test
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

if(UNIX)
  set(Zint_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/share/zint)
  set(ZXing_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/lib/cmake/ZXing)
endif(UNIX)

if(WIN32)
  set(Zint_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/share/zint)
  set(ZXing_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/lib/cmake/ZXing)
endif(WIN32)

find_package(Zint REQUIRED)
find_package(ZXing REQUIRED)
find_package(Threads REQUIRED)

set(Zint_Link_Name zint::zint)
if(BARCODE_LIBS_STATIC)
  set(Zint_Link_Name zint::zint-static)
endif()

set(ZXing_Link_Name ZXing::Core)

target_link_libraries(
  zintzxingcppdemo-test
  ${Zint_Link_Name}
  ${ZXing_Link_Name}
  Threads::Threads
)

enable_testing()

  add_test(
    NAME
    zintzxingcppdemo-test
    COMMAND
    zintzxingcppdemo-test
  )

