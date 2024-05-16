cmake_minimum_required(VERSION 3.18)

project(zintzxingcppdemo-test)

file(GLOB PRO_SRCS_CXX "*.h" "*.cpp")
file(GLOB PRO_SRCS_C "*.c")

set(Zint_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/share/zint)
set(ZXing_DIR ${ZintZXingCppDemo_BINARY_DIR}/deps/build/prefix/lib/cmake/ZXing)

find_package(Zint REQUIRED)
find_package(ZXing REQUIRED)
find_package(Threads REQUIRED)

set(Zint_Link_Name zint::zint)
if(BARCODE_LIBS_STATIC)
  set(Zint_Link_Name zint::zint-static)
endif()

set(ZXing_Link_Name ZXing::Core)

enable_testing()

add_executable(zintzxingcppdemo-test ${PRO_SRCS_CXX})

target_include_directories(
  zintzxingcppdemo-test
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

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
endif()

if(SANITIZE_MODE)
  target_compile_options(
    zintzxingcppdemo-test
  PRIVATE
    -DSANITIZE_MODE -fsanitize=address
  )

  target_link_options(
    zintzxingcppdemo-test
  PRIVATE
    -fsanitize=address
  )
endif()

target_link_libraries(
  zintzxingcppdemo-test
  ${Zint_Link_Name}
  ${ZXing_Link_Name}
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

    if(SANITIZE_MODE)
      target_compile_options(
        ${CRASH_REPRO_BASE}
      PRIVATE
        -DSANITIZE_MODE -fsanitize=address
      )

      target_link_options(
        ${CRASH_REPRO_BASE}
      PRIVATE
        -fsanitize=address
      )
    endif()

    target_link_libraries(
      ${CRASH_REPRO_BASE}
      ${Zint_Link_Name}
      ${ZXing_Link_Name}
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
