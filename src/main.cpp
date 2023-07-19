#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "barcode.h"

bool testNoRotation(
  const std::string& /*testname*/,
  const std::string& symbology,
  const std::string& data,
  const RGBPixelData& rgb
)
{
  bool res = true;

  bool valid = true;
  try {
    valid = validateBarcode(symbology, data, rgb);
  } catch (...) {
    res = false;
  }

  if (!res) {
    return res;
  }

  if (!valid) {
    return false;
  }

  return res;
}

bool test(
  const std::string& symbology,
  const std::map<std::string, std::string>& options,
  const std::string& data,
  int height = 200
)
{
  bool res = true;

  std::string testname;
  testname += symbology;
  for (auto p : options) {
    testname += "-" + p.first;
    testname += "-" + p.second;
  }
  testname += "-" + data;
  testname += "-" + std::to_string(height);

  RGBPixelData rgb;
  try {
    rgb = barcode(symbology, options, data, height);
#if 0
    std::string filename;
    filename += "bc";
    filename += "-" + testname;
    filename += ".ppm";
    rgb.savePPMAscii(filename);
#endif
  } catch (...) {
    res = false;
  }

  if (!res) {
    std::cerr << 0 << " --- " << testname << std::endl;
    return res;
  }

  if (!testNoRotation(testname, symbology, data, rgb)) {
    std::cerr << 0 << " --- " << testname << std::endl;
    return false;
  }

  if (!testNoRotation(testname, symbology, data, rgb.rotate90())) {
    std::cerr << 0 << " --- " << testname << std::endl;
    return false;
  }

  if (!testNoRotation(testname, symbology, data, rgb.rotate180())) {
    std::cerr << 0 << " --- " << testname << std::endl;
    return false;
  }

  if (!testNoRotation(testname, symbology, data, rgb.rotate270())) {
    std::cerr << 0 << " --- " << testname << std::endl;
    return false;
  }

  return true;
}

#define BARCODE_TEST(name, symbology, data) \
  { \
    bool res = test( \
        symbology, \
        std::map<std::string, std::string>{}, \
        data \
    ); \
    count_ok += (res == true ? 1 : 0); \
    count_failed += (res == false ? 1 : 0); \
  }

#define BARCODE_OPTIONS1(name, symbology, option1Name, option1Value, data) \
  { \
    bool res = test( \
        symbology, \
        std::map<std::string, std::string>{ \
          {option1Name, option1Value} \
        }, \
        data \
    ); \
    count_ok += (res == true ? 1 : 0); \
    count_failed += (res == false ? 1 : 0); \
  }

#define BARCODE_OPTIONS2(name, symbology, option1Name, option1Value, option2Name, option2Value, data) \
  { \
    bool res = test( \
        symbology, \
        std::map<std::string, std::string>{ \
          {option1Name, option1Value}, \
          {option2Name, option2Value} \
        }, \
        data \
    ); \
    count_ok += (res == true ? 1 : 0); \
    count_failed += (res == false ? 1 : 0); \
  }

int main()
{
    size_t count_ok = 0;
    size_t count_failed = 0;

BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_1, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "1", "QR CODE")  // NOLINT

    std::cerr << count_failed << " of " << count_failed+count_ok << " tests failed" << std::endl;

    return (count_failed != 0);
}
