#pragma once

#include <memory>
#include <string>

#include "testoptions.h"

class Test
{
public:
  using TestOptionsPtr = std::shared_ptr<TestOptions>;

public:
  explicit Test( const std::string& name, const TestOptionsPtr& options );
  virtual ~Test() = default;

protected:
  std::string m_name;

  TestOptionsPtr m_options;
};

