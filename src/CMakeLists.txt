cmake_minimum_required(VERSION 3.18)

project(BarcodeReader)

file(GLOB PRO_SRCS
      "*.h"
      "*.cpp")

add_executable(BarcodeReader ${PRO_SRCS})

target_include_directories(
  BarcodeReader
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
  BarcodeReader
  ${Zint_Link_Name}
  ${ZXing_Link_Name}
  Threads::Threads
)

enable_testing()

  add_test(
    NAME
    BarcodeReader
    COMMAND
    BarcodeReader
  )

