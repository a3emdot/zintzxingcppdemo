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

SOURCE_DIR=${WORKSPACE}/
BINARY_DIR=${WORKSPACE}/build/${CI_JOB_NAME}

cmake -E rm -rf         ${BINARY_DIR}
cmake -E make_directory ${BINARY_DIR}
cmake -E chdir          ${BINARY_DIR} cmake -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ${CMAKE_ARGS} -DUPSTREAM_MODE=On ${SOURCE_DIR}
cmake -E chdir          ${BINARY_DIR} cmake --build . --config ${CMAKE_BUILD_TYPE}
cmake -E chdir          ${BINARY_DIR}/src ctest -C ${CMAKE_BUILD_TYPE}

