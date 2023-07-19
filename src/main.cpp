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

BARCODE_TEST(QRCODE, "QRCODE", "QR CODE")  // NOLINT

BARCODE_OPTIONS1(QRCODE_ECCLevel_L, "QRCODE", "QRCode_ECCLevel", "L", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_ECCLevel_M, "QRCODE", "QRCode_ECCLevel", "M", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_ECCLevel_Q, "QRCODE", "QRCode_ECCLevel", "Q", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_ECCLevel_H, "QRCODE", "QRCode_ECCLevel", "H", "QR CODE")  // NOLINT

BARCODE_OPTIONS1(QRCODE_Version_1, "QRCODE", "QRCode_Version", "1", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_2, "QRCODE", "QRCode_Version", "2", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_3, "QRCODE", "QRCode_Version", "3", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_4, "QRCODE", "QRCode_Version", "4", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_5, "QRCODE", "QRCode_Version", "5", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_6, "QRCODE", "QRCode_Version", "6", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_7, "QRCODE", "QRCode_Version", "7", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_8, "QRCODE", "QRCode_Version", "8", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_9, "QRCODE", "QRCode_Version", "9", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_10, "QRCODE", "QRCode_Version", "10", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_11, "QRCODE", "QRCode_Version", "11", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_12, "QRCODE", "QRCode_Version", "12", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_13, "QRCODE", "QRCode_Version", "13", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_14, "QRCODE", "QRCode_Version", "14", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_15, "QRCODE", "QRCode_Version", "15", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_16, "QRCODE", "QRCode_Version", "16", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_17, "QRCODE", "QRCode_Version", "17", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_18, "QRCODE", "QRCode_Version", "18", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_19, "QRCODE", "QRCode_Version", "19", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_20, "QRCODE", "QRCode_Version", "20", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_21, "QRCODE", "QRCode_Version", "21", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_22, "QRCODE", "QRCode_Version", "22", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_23, "QRCODE", "QRCode_Version", "23", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_24, "QRCODE", "QRCode_Version", "24", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_25, "QRCODE", "QRCode_Version", "25", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_26, "QRCODE", "QRCode_Version", "26", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_27, "QRCODE", "QRCode_Version", "27", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_28, "QRCODE", "QRCode_Version", "28", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_29, "QRCODE", "QRCode_Version", "29", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_30, "QRCODE", "QRCode_Version", "30", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_31, "QRCODE", "QRCode_Version", "31", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_32, "QRCODE", "QRCode_Version", "32", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_33, "QRCODE", "QRCode_Version", "33", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_34, "QRCODE", "QRCode_Version", "34", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_35, "QRCODE", "QRCode_Version", "35", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_36, "QRCODE", "QRCode_Version", "36", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_37, "QRCODE", "QRCode_Version", "37", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_38, "QRCODE", "QRCode_Version", "38", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_39, "QRCODE", "QRCode_Version", "39", "QR CODE")  // NOLINT
BARCODE_OPTIONS1(QRCODE_Version_40, "QRCODE", "QRCode_Version", "40", "QR CODE")  // NOLINT

BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_1, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "1", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_2, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "2", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_3, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "3", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_4, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "4", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_5, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "5", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_6, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "6", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_7, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "7", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_8, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "8", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_9, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "9", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_10, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "10", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_11, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "11", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_12, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "12", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_13, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "13", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_14, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "14", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_15, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "15", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_16, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "16", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_17, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "17", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_18, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "18", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_19, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "19", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_20, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "20", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_21, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "21", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_22, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "22", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_23, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "23", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_24, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "24", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_25, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "25", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_26, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "26", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_27, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "27", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_28, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "28", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_29, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "29", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_30, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "30", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_31, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "31", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_32, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "32", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_33, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "33", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_34, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "34", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_35, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "35", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_36, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "36", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_37, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "37", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_38, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "38", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_39, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "39", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_L_Version_40, "QRCODE", "QRCode_ECCLevel", "L", "QRCode_Version", "40", "QR CODE")  // NOLINT

BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_1, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "1", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_2, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "2", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_3, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "3", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_4, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "4", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_5, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "5", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_6, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "6", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_7, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "7", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_8, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "8", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_9, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "9", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_10, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "10", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_11, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "11", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_12, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "12", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_13, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "13", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_14, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "14", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_15, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "15", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_16, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "16", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_17, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "17", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_18, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "18", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_19, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "19", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_20, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "20", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_21, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "21", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_22, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "22", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_23, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "23", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_24, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "24", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_25, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "25", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_26, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "26", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_27, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "27", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_28, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "28", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_29, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "29", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_30, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "30", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_31, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "31", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_32, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "32", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_33, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "33", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_34, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "34", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_35, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "35", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_36, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "36", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_37, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "37", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_38, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "38", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_39, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "39", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_M_Version_40, "QRCODE", "QRCode_ECCLevel", "M", "QRCode_Version", "40", "QR CODE")  // NOLINT

BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_1, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "1", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_2, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "2", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_3, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "3", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_4, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "4", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_5, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "5", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_6, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "6", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_7, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "7", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_8, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "8", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_9, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "9", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_10, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "10", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_11, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "11", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_12, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "12", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_13, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "13", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_14, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "14", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_15, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "15", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_16, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "16", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_17, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "17", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_18, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "18", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_19, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "19", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_20, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "20", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_21, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "21", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_22, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "22", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_23, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "23", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_24, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "24", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_25, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "25", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_26, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "26", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_27, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "27", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_28, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "28", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_29, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "29", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_30, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "30", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_31, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "31", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_32, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "32", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_33, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "33", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_34, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "34", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_35, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "35", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_36, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "36", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_37, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "37", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_38, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "38", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_39, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "39", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_Q_Version_40, "QRCODE", "QRCode_ECCLevel", "Q", "QRCode_Version", "40", "QR CODE")  // NOLINT

BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_1, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "1", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_2, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "2", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_3, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "3", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_4, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "4", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_5, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "5", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_6, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "6", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_7, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "7", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_8, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "8", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_9, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "9", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_10, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "10", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_11, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "11", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_12, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "12", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_13, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "13", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_14, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "14", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_15, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "15", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_16, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "16", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_17, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "17", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_18, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "18", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_19, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "19", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_20, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "20", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_21, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "21", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_22, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "22", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_23, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "23", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_24, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "24", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_25, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "25", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_26, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "26", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_27, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "27", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_28, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "28", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_29, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "29", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_30, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "30", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_31, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "31", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_32, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "32", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_33, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "33", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_34, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "34", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_35, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "35", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_36, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "36", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_37, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "37", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_38, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "38", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_39, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "39", "QR CODE")  // NOLINT
BARCODE_OPTIONS2(QRCODE_ECCLevel_H_Version_40, "QRCODE", "QRCode_ECCLevel", "H", "QRCode_Version", "40", "QR CODE")  // NOLINT

    std::cerr << count_failed << " of " << count_failed+count_ok << " tests failed" << std::endl;

    return (count_failed != 0);
}
