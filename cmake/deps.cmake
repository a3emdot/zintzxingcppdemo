include(FetchContent)

set(ZINT_VERSION "2.13.0")
set(ZINT_MASTER_DIR https://github.com/zint/zint/archive)
set(ZINT_MASTER_FILE ${ZINT_MASTER_DIR}/${ZINT_VERSION}.tar.gz)
set(ZINT_SHA256 "480d95e46d2a2dae204c0f2b6433f185aba50786a0f00d1420752a6e287311ec")

FetchContent_Declare(
  zint
  URL      ${ZINT_MASTER_FILE}
  URL_HASH SHA256=${ZINT_SHA256}
)

set(ZINT_TEST OFF CACHE INTERNAL "")
set(ZINT_USE_QT OFF CACHE INTERNAL "")
set(ZINT_USE_PNG OFF CACHE INTERNAL "")

if(BARCODE_LIBS_STATIC)
  set(ZINT_SHARED OFF CACHE INTERNAL "")
  set(ZINT_STATIC ON CACHE INTERNAL "")
endif()
if(FUZZER_MODE OR SANITIZE_MODE)
  set(ZINT_SANITIZE ON CACHE INTERNAL "")
  set(SANITZERS address CACHE INTERNAL "")
endif()

set(ZXING_VERSION "2.2.1")
set(ZXING_MASTER_DIR https://github.com/nu-book/zxing-cpp/archive)
set(ZXING_MASTER_FILE ${ZXING_MASTER_DIR}/v${ZXING_VERSION}.tar.gz)
set(ZXING_SHA256 "02078ae15f19f9d423a441f205b1d1bee32349ddda7467e2c84e8f08876f8635")

FetchContent_Declare(
  zxing
  URL      ${ZXING_MASTER_FILE}
  URL_HASH SHA256=${ZXING_SHA256}
)

set(BUILD_WRITERS OFF CACHE INTERNAL "")
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(BUILD_BLACKBOX_TESTS OFF CACHE INTERNAL "")
set(BUILD_UNIT_TESTS OFF CACHE INTERNAL "")
set(BUILD_PYTHON_MODULE OFF CACHE INTERNAL "")
if(BARCODE_LIBS_STATIC)
  set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
else()
  set(BUILD_SHARED_LIBS ON CACHE INTERNAL "")
endif()

FetchContent_MakeAvailable(zint zxing)

if(BARCODE_LIBS_STATIC)
	add_library(zint::zint-static ALIAS zint-static)
else()
	add_library(zint::zint ALIAS zint)
endif()
