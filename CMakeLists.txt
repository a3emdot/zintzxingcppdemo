cmake_minimum_required(VERSION 3.18)

project(ZintZXingCppDemo)

option(FUZZER_MODE "Enable fuzzer mode" OFF)
option(SANITIZE_MODE "Enable sanitize mode" OFF)
option(BARCODE_LIBS_STATIC "Use static libraries" OFF)

file(GLOB PRO_SRCS_CXX "src/*.h" "src/*.cpp")
file(GLOB PRO_SRCS_C "src/*.c")

set(Zint_DIR ${PROJECT_BINARY_DIR}/deps/instal/share/zint)
set(ZXing_DIR ${PROJECT_BINARY_DIR}/deps/instal/lib/cmake/ZXing)

find_package(Zint REQUIRED)
find_package(ZXing REQUIRED)
find_package(Threads REQUIRED)

enable_testing()

add_executable(zintzxingcppdemo-test ${PRO_SRCS_CXX})

target_include_directories( zintzxingcppdemo-test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
target_compile_options( zintzxingcppdemo-test PRIVATE
  $<$<BOOL:${FUZZER_MODE}>:-fsanitize=fuzzer,address>
  $<$<BOOL:${SANITIZE_MODE}>:-fsanitize=address>
)
target_compile_definitions( zintzxingcppdemo-test PRIVATE
  $<$<BOOL:${FUZZER_MODE}>:FUZZER_MODE>
  $<$<BOOL:${SANITIZE_MODE}>:SANITIZE_MODE>
)
target_link_options( zintzxingcppdemo-test PRIVATE
  $<$<BOOL:${FUZZER_MODE}>:-fsanitize=fuzzer,address>
  $<$<BOOL:${SANITIZE_MODE}>:-fsanitize=address>
)
target_link_libraries( zintzxingcppdemo-test PRIVATE
  $<IF:$<BOOL:${BARCODE_LIBS_STATIC}>,zint::zint-static,zint::zint>
  ZXing::Core
  Threads::Threads
)

add_test(
  NAME
  zintzxingcppdemo-test
  COMMAND
  zintzxingcppdemo-test
)

if(NOT FUZZER_MODE)
  foreach(CRASH_REPRO IN LISTS PRO_SRCS_C)
    get_filename_component(
      CRASH_REPRO_BASE
      ${CRASH_REPRO}
      NAME_WE
    )

    add_executable(
      ${CRASH_REPRO_BASE}
      ${CRASH_REPRO}
    )

    target_compile_options( ${CRASH_REPRO_BASE} PRIVATE
      $<$<BOOL:${SANITIZE_MODE}>:-fsanitize=address>
    )
    target_compile_definitions( ${CRASH_REPRO_BASE} PRIVATE
      $<$<BOOL:${SANITIZE_MODE}>:SANITIZE_MODE>
    )
    target_link_options( ${CRASH_REPRO_BASE} PRIVATE
      $<$<BOOL:${SANITIZE_MODE}>:-fsanitize=address>
    )

    target_link_libraries( ${CRASH_REPRO_BASE} PRIVATE
      $<IF:$<BOOL:${BARCODE_LIBS_STATIC}>,zint::zint-static,zint::zint>
      ZXing::Core
      Threads::Threads
    )

    add_test(
      NAME
      ${CRASH_REPRO_BASE}
      COMMAND
      ${CRASH_REPRO_BASE}
    )
  endforeach()
endif()

