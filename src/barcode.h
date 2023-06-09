#pragma once

#include <map>
#include <string>

#include "rgbpixeldata.h"

RGBPixelData barcode(
    const std::string& symbology,
    const std::map<std::string, std::string>& options,
    const std::string& data,
    unsigned int height
);

bool validateBarcode(
  const std::string& symbology,
  const std::string& data,
  const RGBPixelData& rgb
);

