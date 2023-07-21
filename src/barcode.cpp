#include "barcode.h"

#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

#include <zint.h>
#include <ZXing/ReadBarcode.h>

int zintSymbology(const std::string& symbology)
{
  if (symbology == "UPCA") {
    return BARCODE_UPCA;
  }
  if (symbology == "UPCA_CHK") {
    return BARCODE_UPCA_CHK;
  }
  if (symbology == "EAN8") {
    return BARCODE_EANX;
  }
  if (symbology == "EAN8_CHK") {
    return BARCODE_EANX_CHK;
  }
  if (symbology == "EAN13") {
    return BARCODE_EANX;
  }
  if (symbology == "EAN13_CHK") {
    return BARCODE_EANX_CHK;
  }
  if (symbology == "GS1_128") {
    return BARCODE_GS1_128;
  }
  if (symbology == "CODE128") {
    return BARCODE_CODE128;
  }
  if (symbology == "GS1_DBAR_OMN") {
    return BARCODE_DBAR_OMN;
  }
  if (symbology == "GS1_DBAR_EXP") {
    return BARCODE_DBAR_EXP;
  }
  if (symbology == "GS1_DBAR_OMNSTK") {
    return BARCODE_DBAR_OMNSTK;
  }
  if (symbology == "GS1_DBAR_EXPSTK") {
    return BARCODE_DBAR_EXPSTK;
  }
  if (symbology == "AZTEC") {
    return BARCODE_AZTEC;
  }
  if (symbology == "GS1_DATAMATRIX") {
    return BARCODE_DATAMATRIX;
  }
  if (symbology == "QRCODE") {
    return BARCODE_QRCODE;
  }
  throw std::runtime_error("unsupported barcode symbology");
}

int zintInputMode(const std::string& symbology)
{
  if (symbology == "UPCA") {
    return DATA_MODE;
  }
  if (symbology == "UPCA_CHK") {
    return DATA_MODE;
  }
  if (symbology == "EAN8") {
    return DATA_MODE;
  }
  if (symbology == "EAN8_CHK") {
    return DATA_MODE;
  }
  if (symbology == "EAN13") {
    return DATA_MODE;
  }
  if (symbology == "EAN13_CHK") {
    return DATA_MODE;
  }
  if (symbology == "GS1_128") {
    return DATA_MODE | GS1PARENS_MODE;
  }
  if (symbology == "CODE128") {
    return DATA_MODE;
  }
  if (symbology == "GS1_DBAR_OMN") {
    return DATA_MODE | GS1PARENS_MODE;
  }
  if (symbology == "GS1_DBAR_EXP") {
    return DATA_MODE | GS1PARENS_MODE;
  }
  if (symbology == "GS1_DBAR_OMNSTK") {
    return DATA_MODE | GS1PARENS_MODE;
  }
  if (symbology == "GS1_DBAR_EXPSTK") {
    return DATA_MODE | GS1PARENS_MODE;
  }
  if (symbology == "AZTEC") {
    return DATA_MODE;
  }
  if (symbology == "GS1_DATAMATRIX") {
    return DATA_MODE | GS1_MODE | GS1PARENS_MODE;
  }
  if (symbology == "QRCODE") {
    return DATA_MODE;
  }
  throw std::runtime_error("unsupported barcode symbology");
}

int zintShowHRT(const std::string& symbology, bool flag)
{
  int res = 0;
  if (flag) {
    res = 1;
  }

  if (symbology == "UPCA") {
    return res;
  }
  if (symbology == "UPCA_CHK") {
    return res;
  }
  if (symbology == "EAN8") {
    return res;
  }
  if (symbology == "EAN8_CHK") {
    return res;
  }
  if (symbology == "EAN13") {
    return res;
  }
  if (symbology == "EAN13_CHK") {
    return res;
  }
  if (symbology == "GS1_128") {
    return res;
  }
  if (symbology == "CODE128") {
    return res;
  }
  if (symbology == "GS1_DBAR_OMN") {
    return res;
  }
  if (symbology == "GS1_DBAR_EXP") {
    return res;
  }
  if (symbology == "GS1_DBAR_OMNSTK") {
    return 0;
  }
  if (symbology == "GS1_DBAR_EXPSTK") {
    return 0;
  }
  if (symbology == "AZTEC") {
    return 0;
  }
  if (symbology == "GS1_DATAMATRIX") {
    return 0;
  }
  if (symbology == "QRCODE") {
    return 0;
  }
  throw std::runtime_error("unsupported barcode symbology");
}

float zintHeight(
  const std::string& /*symbology*/, unsigned int height
)
{
  if (height != 0) {
    return height;
  }
  throw std::runtime_error("unsupported barcode zero height");
}

int symbolOptionFromAztecCode_ECCPercent(const std::string& errorCorrectionPercent)
{
  return std::map<std::string, int>{
    {"10", 1},
    {"23", 2},
    {"36", 3},
    {"50", 4}
  }.at(errorCorrectionPercent);
}

int symbolOptionFromAztecCode_Size(const std::string& size)
{
  return std::map<std::string, int>{
    {"19_19", 5},
    {"23_23", 6},
    {"27_27", 7},
    {"31_31", 8},
    {"37_37", 9},
    {"41_41", 10},
    {"45_45", 11},
    {"49_49", 12},
    {"53_53", 13},
    {"57_57", 14},
    {"61_61", 15},
    {"67_67", 16},
    {"71_71", 17},
    {"75_75", 18},
    {"79_79", 19},
    {"83_83", 20},
    {"87_87", 21},
    {"91_91", 22},
    {"95_95", 23},
    {"101_101", 24},
    {"105_105", 25},
    {"109_109", 26},
    {"113_113", 27},
    {"117_117", 28},
    {"121_121", 29},
    {"125_125", 30},
    {"131_131", 31},
    {"135_135", 32},
    {"139_139", 33},
    {"143_143", 34},
    {"147_147", 35},
    {"151_151", 36}
  }.at(size);
}

int symbolOptionFromGS1DataMatrix_Size(const std::string& size)
{
  return std::map<std::string, int>{
    {"10_10", 1},
    {"12_12", 2},
    {"14_14", 3},
    {"16_16", 4},
    {"18_18", 5},
    {"20_20", 6},
    {"22_22", 7},
    {"24_24", 8},
    {"26_26", 9},
    {"32_32", 10},
    {"36_36", 11},
    {"40_40", 12},
    {"44_44", 13},
    {"48_48", 14},
    {"52_52", 15},
    {"64_64", 16},
    {"72_72", 17},
    {"80_80", 18},
    {"88_88", 19},
    {"96_96", 20},
    {"104_104", 21},
    {"120_120", 22},
    {"132_132", 23},
    {"144_144", 24}
  }.at(size);
}

int symbolOptionFromQRCode_ECCLevel(const std::string& errorCorrectionLevel)
{
  return std::map<std::string, int>{
    {"L", 1},
    {"M", 2},
    {"Q", 3},
    {"H", 4}
  }.at(errorCorrectionLevel);
}

int symbolOptionFromQRCode_Version(
  const std::string& version
)
{
  return std::stoi(version);
}

void populateSymbolWithAztecCodeOptions(
  zint_symbol* symbol,
  const std::map<std::string, std::string>& options
)
{
  if (options.count("AztecCode_ECCPercent") != 0U) {
    const auto& value = options.at("AztecCode_ECCPercent");
    symbol->option_1 = symbolOptionFromAztecCode_ECCPercent(value);
  }
  if (options.count("AztecCode_Size") != 0U) {
    const auto& value = options.at("AztecCode_Size");
    symbol->option_2 = symbolOptionFromAztecCode_Size(value);
  }
}

void populateSymbolWithGS1DataMatrixOptions(
  zint_symbol* symbol,
  const std::map<std::string, std::string>& options
)
{
  if (options.count("GS1DataMatrix_Size") != 0U) {
    const auto& value = options.at("GS1DataMatrix_Size");
    symbol->option_2 = symbolOptionFromGS1DataMatrix_Size(value);
  }
  { // allow only square symbols
    symbol->option_3 = DM_SQUARE;
  }
}

void populateSymbolWithQRCodeOptions(
  zint_symbol* symbol,
  const std::map<std::string, std::string>& options
)
{
  if (options.count("QRCode_ECCLevel") != 0U) {
    const auto& value = options.at("QRCode_ECCLevel");
    symbol->option_1 = symbolOptionFromQRCode_ECCLevel(value);
  }
  if (options.count("QRCode_Version") != 0U) {
    const auto& value = options.at("QRCode_Version");
    symbol->option_2 = symbolOptionFromQRCode_Version(value);
  }
}

void populateSymbolWithOptions(
  zint_symbol* symbol,
  const std::map<std::string, std::string>& barcodeOptions
)
{
  switch (symbol->symbology) {
    case BARCODE_AZTEC:
      populateSymbolWithAztecCodeOptions(symbol, barcodeOptions);
      break;
    case BARCODE_DATAMATRIX:
      populateSymbolWithGS1DataMatrixOptions(symbol, barcodeOptions);
      break;
    case BARCODE_QRCODE:
      populateSymbolWithQRCodeOptions(symbol, barcodeOptions);
      break;
    default:
      (void)0;
  }
}

int zintFixZintSymbology(const std::string& input, int zintsymbology)
{
  if (zintsymbology == BARCODE_UPCA) {
    if (input.size() == 12) {
      return BARCODE_UPCA_CHK;
    }
  }
  if (zintsymbology == BARCODE_EANX) {
    if (input.size() == 8) {
      return BARCODE_EANX_CHK;
    }
  }
  if (zintsymbology == BARCODE_EANX) {
    if (input.size() == 13) {
      return BARCODE_EANX_CHK;
    }
  }

  return zintsymbology;
}

RGBPixelData extractRGBPixelDataFromSymbol(
  zint_symbol* my_symbol
)
{
  const unsigned int width = my_symbol->bitmap_width;
  const unsigned int height = my_symbol->bitmap_height;
  std::vector<unsigned char> resdata(3*width*height, 0);
  for (unsigned int k = 0; k < width*height; k++) {
    resdata[ 3*k + 0 ] = my_symbol->bitmap[ 3*k + 0 ];
    resdata[ 3*k + 1 ] = my_symbol->bitmap[ 3*k + 1 ];
    resdata[ 3*k + 2 ] = my_symbol->bitmap[ 3*k + 2 ];
  }

  return RGBPixelData(width, height, 3*width, resdata);
}

RGBPixelData barcode(
    const std::string& symbology,
    const std::map<std::string, std::string>& options,
    const std::string& data,
    unsigned int height
)
{
  if (data.empty()) {
    const std::string what = "empty barcode payload unsupported";
    std::cerr << "barcode: exception <" << what << ">" << std::endl;
    throw std::runtime_error(what);
  }

  int zintsymbology = -1;
  try {
    zintsymbology = zintSymbology(symbology);
  } catch (const std::exception& ex) {
    std::cerr << "barcode: exception <" << ex.what() << ">" << std::endl;
    throw std::runtime_error(ex.what());
  }

  int zintinputmode = -1;
  try {
    zintinputmode = zintInputMode(symbology);
  } catch (const std::exception& ex) {
    std::cerr << "barcode: exception <" << ex.what() << ">" << std::endl;
    throw std::runtime_error(ex.what());
  }

  int zintshowhrt = -1;
  try {
    zintshowhrt = zintShowHRT(symbology, true);
  } catch (const std::exception& ex) {
    std::cerr << "barcode: exception <" << ex.what() << ">" << std::endl;
    throw std::runtime_error(ex.what());
  }

  float zintheight = 0.0;
  try {
    zintheight = zintHeight(symbology, height);
  } catch (const std::exception& ex) {
    std::cerr << "barcode: exception <" << ex.what() << ">" << std::endl;
    throw std::runtime_error(ex.what());
  }

  zintsymbology = zintFixZintSymbology(data, zintsymbology);

  std::vector<unsigned char> zintdata(data.cbegin(), data.cend());
  zintdata.push_back('\0');

  // create zint structure
  struct zint_symbol* my_symbol = ZBarcode_Create();

  // prepare zint parameters
  ZBarcode_Clear(my_symbol);
  my_symbol->symbology = zintsymbology;
  my_symbol->input_mode = zintinputmode;
  my_symbol->show_hrt = zintshowhrt;
  my_symbol->height = zintheight;
  populateSymbolWithOptions(my_symbol, options);

  // render zint structure
  if (ZBarcode_Encode_and_Buffer(my_symbol, zintdata.data(), 0, 0) >= ZINT_ERROR) {
    std::string what = std::string("barcode backend error: ") + my_symbol->errtxt;
    std::cerr << "barcode: exception <" << what << ">" << std::endl;

    // destroy zint structure
    ZBarcode_Delete(my_symbol);

    throw std::runtime_error(what);
  }

  // extract rgba pixel data before freeing the symbol
  RGBPixelData rgba = extractRGBPixelDataFromSymbol(my_symbol);

  // destroy zint structure
  ZBarcode_Delete(my_symbol);

  return rgba;
}

ZXing::BarcodeFormat zxingSymbology(const std::string& symbology)
{
  if (symbology == "UPCA") {
    return ZXing::BarcodeFormat::UPCA;
  }
  if (symbology == "UPCA_CHK") {
    return ZXing::BarcodeFormat::UPCA;
  }
  if (symbology == "EAN8") {
    return ZXing::BarcodeFormat::EAN8;
  }
  if (symbology == "EAN8_CHK") {
    return ZXing::BarcodeFormat::EAN8;
  }
  if (symbology == "EAN13") {
    return ZXing::BarcodeFormat::EAN13;
  }
  if (symbology == "EAN13_CHK") {
    return ZXing::BarcodeFormat::EAN13;
  }
  // TODO(AM): check this one vs the CODE128 one
  if (symbology == "GS1_128") {
    return ZXing::BarcodeFormat::Code128;
  }
  if (symbology == "CODE128") {
    return ZXing::BarcodeFormat::Code128;
  }
  if (symbology == "GS1_DBAR_OMN") {
    return ZXing::BarcodeFormat::DataBar;
  }
  if (symbology == "GS1_DBAR_EXP") {
    return ZXing::BarcodeFormat::DataBarExpanded;
  }
  if (symbology == "GS1_DBAR_OMNSTK") {
    return ZXing::BarcodeFormat::DataBar;
  }
  if (symbology == "GS1_DBAR_EXPSTK") {
    return ZXing::BarcodeFormat::DataBarExpanded;
  }
  if (symbology == "AZTEC") {
    return ZXing::BarcodeFormat::Aztec;
  }
  if (symbology == "GS1_DATAMATRIX") {
    return ZXing::BarcodeFormat::DataMatrix;
  }
  if (symbology == "QRCODE") {
    return ZXing::BarcodeFormat::QRCode;
  }
  throw std::runtime_error("unsupported barcode symbology");
}

std::string zxingFixReadData(
  int zintsymbology,
  const std::string& writtendata,
  const std::string& readdata
)
{
  if (zintsymbology == BARCODE_UPCA) {
    if (writtendata.size() == 12) {
      return readdata;
    }
    return readdata.substr(0, readdata.size()-1);
  }
  if (zintsymbology == BARCODE_EANX) {
    if (writtendata.size() == 8) {
      return readdata;
    }
    if (writtendata.size() == 13) {
      return readdata;
    }
    return readdata.substr(0, readdata.size()-1);
  }
  return readdata;
}

bool validateBarcodeNoRotation(
  const std::string& symbology,
  const std::string& data,
  const RGBPixelData& rgb
) {
  bool res = true;

  ZXing::BarcodeFormat hintSymbology = ZXing::BarcodeFormat::None;

  try {
    hintSymbology = zxingSymbology(symbology);
  } catch (...) {
    res = false;
  }

  if (!res) {
    return false;
  }

  if (hintSymbology == ZXing::BarcodeFormat::None) {
    res = false;
  }

  ZXing::Result parseresult;
  try {
    ZXing::DecodeHints hints;
    hints.setIsPure(true);
    hints.setFormats(hintSymbology);

    ZXing::ImageView view(rgb.data().data(), rgb.width(), rgb.height(), ZXing::ImageFormat::RGB);

    parseresult = ZXing::ReadBarcode(view, hints);
  } catch (...) {
    res = false;
  }

  if (!res) {
    return false;
  }

  if (!parseresult.isValid()) {
    res = false;
  }

  if (!res) {
    return false;
  }

  std::string writtenData = data;
  std::string readData = parseresult.text();
  try {
    readData = zxingFixReadData(zintSymbology(symbology), writtenData, readData);
  } catch (...) {
    res = false;
  }

  if (!res) {
    return false;
  }

  if (readData != writtenData) {
    res = false;
  }

  if (!res) {
    return false;
  }

  ZXing::BarcodeFormat writtenSymbology = ZXing::BarcodeFormat::None;
  ZXing::BarcodeFormat readSymbology = ZXing::BarcodeFormat::None;
  try {
    writtenSymbology = zxingSymbology(symbology);
    readSymbology = parseresult.format();
  } catch (...) {
    res = false;
  }

  if (!res) {
    return false;
  }

  if (readSymbology == ZXing::BarcodeFormat::None) {
    res = false;
  }
  if (writtenSymbology == ZXing::BarcodeFormat::None) {
    res = false;
  }
  if (readSymbology != writtenSymbology) {
    res = false;
  }

  if (!res) {
    return false;
  }

  return res;
}

bool validateBarcode(
  const std::string& symbology,
  const std::string& data,
  const RGBPixelData& rgb
) {
  bool res = false;

  res |= validateBarcodeNoRotation(symbology, data, rgb);
  res |= validateBarcodeNoRotation(symbology, data, rgb.rotate90());
  res |= validateBarcodeNoRotation(symbology, data, rgb.rotate180());
  res |= validateBarcodeNoRotation(symbology, data, rgb.rotate270());

  return res;
}
