#pragma once

#include <map>
#include <string>

#include "test.h"

class BarcodeTest
  : public Test
{
public:
  BarcodeTest();

  bool test(
    const std::string& symbology,
    const std::map<std::string, std::string>& options,
    const std::string& data,
    int height
  ) const;
};
