#!/bin/sh

set -e
set -x

if test -z ${WORKSPACE+x}; then
    WORKSPACE=$(pwd);
fi

if test -z ${CI_JOB_NAME+x}; then
    CI_JOB_NAME=local;
fi

if test -z ${CMAKE_BUILD_TYPE+x}; then
    CMAKE_BUILD_TYPE=Release;
fi

SOURCE_DIR=${WORKSPACE}
BINARY_DIR=${WORKSPACE}/build/${CI_JOB_NAME}

cmake -E rm -rf         ${BINARY_DIR}
cmake -E make_directory ${BINARY_DIR}/deps

cmake -E copy  ${SOURCE_DIR}/deps/CMakeLists.txt ${BINARY_DIR}/deps/CMakeLists.txt
cmake -E make_directory ${BINARY_DIR}/deps/build

cmake -S ${BINARY_DIR}/deps -B ${BINARY_DIR}/deps/build -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
cmake --build ${BINARY_DIR}/deps/build --config ${CMAKE_BUILD_TYPE}

cmake -S ${SOURCE_DIR} -B ${BINARY_DIR} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ${CMAKE_ARGS} ${SOURCE_DIR}
cmake --build ${BINARY_DIR} --config ${CMAKE_BUILD_TYPE}

cmake -E chdir ${BINARY_DIR} valgrind ./zintzxingcppdemo-test > ${BINARY_DIR}/src/valgrind.log 2>&1
cmake -E chdir ${BINARY_DIR} cat valgrind.log

