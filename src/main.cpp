#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "barcode.h"

bool testNoRotation(
  const std::string& testname,
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
    std::cerr << 0 << " --- " << testname << std::endl;
    return res;
  }

  if (!valid) {
    std::cerr << 0 << " --- " << testname << std::endl;
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

BARCODE_TEST(UPCA_1, "UPCA", "00000012345")  // NOLINT
BARCODE_TEST(UPCA_2, "UPCA", "12345678901")  // NOLINT
BARCODE_TEST(UPCA_3, "UPCA", "000000123457")  // NOLINT
BARCODE_TEST(UPCA_4, "UPCA", "123456789012")  // NOLINT
BARCODE_TEST(UPCA_CHK_1, "UPCA_CHK", "000000123457")  // NOLINT
BARCODE_TEST(UPCA_CHK_2, "UPCA_CHK", "123456789012")  // NOLINT

BARCODE_TEST(EAN8_1, "EAN8", "0123456")  // NOLINT
BARCODE_TEST(EAN8_2, "EAN8", "4321056")  // NOLINT
BARCODE_TEST(EAN8_3, "EAN8", "01234565")  // NOLINT
BARCODE_TEST(EAN8_4, "EAN8", "43210565")  // NOLINT
BARCODE_TEST(EAN8_CHK_1, "EAN8_CHK", "01234565")  // NOLINT
BARCODE_TEST(EAN8_CHK_2, "EAN8_CHK", "43210565")  // NOLINT
BARCODE_TEST(EAN13_1, "EAN13", "012345678901")  // NOLINT
BARCODE_TEST(EAN13_2, "EAN13", "432105678901")  // NOLINT
BARCODE_TEST(EAN13_3, "EAN13", "0123456789012")  // NOLINT
BARCODE_TEST(EAN13_4, "EAN13", "4321056789012")  // NOLINT
BARCODE_TEST(EAN13_CHK_1, "EAN13_CHK", "0123456789012")  // NOLINT
BARCODE_TEST(EAN13_CHK_2, "EAN13_CHK", "4321056789012")  // NOLINT

BARCODE_TEST(GS1_128, "GS1_128", "(01)12345678901231")  // NOLINT
BARCODE_TEST(CODE128, "CODE128", "121212121212121212121")  // NOLINT

BARCODE_TEST(GS1_DBAR_OMN, "GS1_DBAR_OMN", "12345678901231")  // NOLINT
BARCODE_TEST(GS1_DBAR_OMNSTK, "GS1_DBAR_OMNSTK", "12345678901231")  // NOLINT
BARCODE_TEST(GS1_DBAR_EXP, "GS1_DBAR_EXP", "(01)00000000045681(3203)000049")  // NOLINT
BARCODE_TEST(GS1_DBAR_EXPSTK, "GS1_DBAR_EXPSTK", "(01)02229999000008(91)000111000003001390103")  // NOLINT

BARCODE_TEST(AZTEC, "AZTEC", "121212121abcd")  // NOLINT

BARCODE_OPTIONS1(AZTEC_ECCPercent_10, "AZTEC", "AztecCode_ECCPercent", "10", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_ECCPercent_23, "AZTEC", "AztecCode_ECCPercent", "23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_ECCPercent_36, "AZTEC", "AztecCode_ECCPercent", "36", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_ECCPercent_50, "AZTEC", "AztecCode_ECCPercent", "50", "121212121abcd")  // NOLINT

BARCODE_OPTIONS1(AZTEC_Size_19_19, "AZTEC", "AztecCode_Size", "19_19", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_23_23, "AZTEC", "AztecCode_Size", "23_23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_27_27, "AZTEC", "AztecCode_Size", "27_27", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_31_31, "AZTEC", "AztecCode_Size", "31_31", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_37_37, "AZTEC", "AztecCode_Size", "37_37", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_41_41, "AZTEC", "AztecCode_Size", "41_41", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_45_45, "AZTEC", "AztecCode_Size", "45_45", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_49_49, "AZTEC", "AztecCode_Size", "49_49", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_53_53, "AZTEC", "AztecCode_Size", "53_53", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_57_57, "AZTEC", "AztecCode_Size", "57_57", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_61_61, "AZTEC", "AztecCode_Size", "61_61", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_67_67, "AZTEC", "AztecCode_Size", "67_67", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_71_71, "AZTEC", "AztecCode_Size", "71_71", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_75_75, "AZTEC", "AztecCode_Size", "75_75", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_79_79, "AZTEC", "AztecCode_Size", "79_79", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_83_83, "AZTEC", "AztecCode_Size", "83_83", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_87_87, "AZTEC", "AztecCode_Size", "87_87", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_91_91, "AZTEC", "AztecCode_Size", "91_91", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_95_95, "AZTEC", "AztecCode_Size", "95_95", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_101_101, "AZTEC", "AztecCode_Size", "101_101", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_105_105, "AZTEC", "AztecCode_Size", "105_105", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_109_109, "AZTEC", "AztecCode_Size", "109_109", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_113_113, "AZTEC", "AztecCode_Size", "113_113", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_117_117, "AZTEC", "AztecCode_Size", "117_117", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_121_121, "AZTEC", "AztecCode_Size", "121_121", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_125_125, "AZTEC", "AztecCode_Size", "125_125", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_131_131, "AZTEC", "AztecCode_Size", "131_131", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_135_135, "AZTEC", "AztecCode_Size", "135_135", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_139_139, "AZTEC", "AztecCode_Size", "139_139", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_143_143, "AZTEC", "AztecCode_Size", "143_143", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_147_147, "AZTEC", "AztecCode_Size", "147_147", "121212121abcd")  // NOLINT
BARCODE_OPTIONS1(AZTEC_Size_151_151, "AZTEC", "AztecCode_Size", "151_151", "121212121abcd")  // NOLINT

BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_19_19, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "19_19", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_23_23, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "23_23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_27_27, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "27_27", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_31_31, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "31_31", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_37_37, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "37_37", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_41_41, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "41_41", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_45_45, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "45_45", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_49_49, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "49_49", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_53_53, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "53_53", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_57_57, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "57_57", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_61_61, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "61_61", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_67_67, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "67_67", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_71_71, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "71_71", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_75_75, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "75_75", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_79_79, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "79_79", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_83_83, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "83_83", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_87_87, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "87_87", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_91_91, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "91_91", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_95_95, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "95_95", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_101_101, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "101_101", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_105_105, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "105_105", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_109_109, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "109_109", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_113_113, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "113_113", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_117_117, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "117_117", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_121_121, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "121_121", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_125_125, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "125_125", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_131_131, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "131_131", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_135_135, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "135_135", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_139_139, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "139_139", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_143_143, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "143_143", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_147_147, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "147_147", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_10_Size_151_151, "AZTEC", "AztecCode_ECCPercent", "10", "AztecCode_Size", "151_151", "121212121abcd")  // NOLINT

BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_19_19, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "19_19", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_23_23, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "23_23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_27_27, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "27_27", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_31_31, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "31_31", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_37_37, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "37_37", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_41_41, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "41_41", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_45_45, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "45_45", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_49_49, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "49_49", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_53_53, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "53_53", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_57_57, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "57_57", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_61_61, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "61_61", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_67_67, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "67_67", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_71_71, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "71_71", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_75_75, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "75_75", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_79_79, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "79_79", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_83_83, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "83_83", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_87_87, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "87_87", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_91_91, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "91_91", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_95_95, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "95_95", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_101_101, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "101_101", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_105_105, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "105_105", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_109_109, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "109_109", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_113_113, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "113_113", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_117_117, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "117_117", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_121_121, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "121_121", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_125_125, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "125_125", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_131_131, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "131_131", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_135_135, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "135_135", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_139_139, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "139_139", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_143_143, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "143_143", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_147_147, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "147_147", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_23_Size_151_151, "AZTEC", "AztecCode_ECCPercent", "23", "AztecCode_Size", "151_151", "121212121abcd")  // NOLINT

BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_19_19, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "19_19", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_23_23, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "23_23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_27_27, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "27_27", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_31_31, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "31_31", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_37_37, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "37_37", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_41_41, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "41_41", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_45_45, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "45_45", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_49_49, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "49_49", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_53_53, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "53_53", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_57_57, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "57_57", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_61_61, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "61_61", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_67_67, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "67_67", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_71_71, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "71_71", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_75_75, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "75_75", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_79_79, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "79_79", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_83_83, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "83_83", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_87_87, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "87_87", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_91_91, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "91_91", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_95_95, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "95_95", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_101_101, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "101_101", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_105_105, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "105_105", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_109_109, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "109_109", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_113_113, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "113_113", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_117_117, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "117_117", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_121_121, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "121_121", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_125_125, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "125_125", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_131_131, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "131_131", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_135_135, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "135_135", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_139_139, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "139_139", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_143_143, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "143_143", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_147_147, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "147_147", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_36_Size_151_151, "AZTEC", "AztecCode_ECCPercent", "36", "AztecCode_Size", "151_151", "121212121abcd")  // NOLINT

BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_19_19, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "19_19", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_23_23, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "23_23", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_27_27, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "27_27", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_31_31, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "31_31", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_37_37, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "37_37", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_41_41, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "41_41", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_45_45, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "45_45", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_49_49, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "49_49", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_53_53, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "53_53", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_57_57, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "57_57", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_61_61, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "61_61", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_67_67, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "67_67", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_71_71, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "71_71", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_75_75, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "75_75", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_79_79, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "79_79", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_83_83, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "83_83", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_87_87, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "87_87", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_91_91, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "91_91", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_95_95, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "95_95", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_101_101, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "101_101", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_105_105, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "105_105", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_109_109, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "109_109", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_113_113, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "113_113", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_117_117, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "117_117", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_121_121, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "121_121", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_125_125, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "125_125", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_131_131, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "131_131", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_135_135, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "135_135", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_139_139, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "139_139", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_143_143, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "143_143", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_147_147, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "147_147", "121212121abcd")  // NOLINT
BARCODE_OPTIONS2(AZTEC_ECCPercent_50_Size_151_151, "AZTEC", "AztecCode_ECCPercent", "50", "AztecCode_Size", "151_151", "121212121abcd")  // NOLINT

BARCODE_TEST(GS1_DATAMATRIX, "GS1_DATAMATRIX", "(20)01")  // NOLINT

BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_10_10, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "10_10", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_12_12, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "12_12", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_14_14, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "14_14", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_16_16, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "16_16", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_18_18, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "18_18", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_20_20, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "20_20", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_22_22, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "22_22", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_24_24, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "24_24", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_26_26, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "26_26", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_32_32, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "32_32", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_36_36, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "36_36", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_40_40, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "40_40", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_44_44, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "44_44", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_48_48, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "48_48", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_52_52, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "52_52", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_64_64, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "64_64", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_72_72, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "72_72", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_80_80, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "80_80", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_88_88, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "88_88", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_96_96, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "96_96", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_104_104, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "104_104", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_120_120, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "120_120", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_132_132, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "132_132", "(20)01")  // NOLINT
BARCODE_OPTIONS1(GS1_DATAMATRIX_Size_144_144, "GS1_DATAMATRIX", "GS1DataMatrix_Size", "144_144", "(20)01")  // NOLINT

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
