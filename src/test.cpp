#include "test.h"

Test::Test( const std::string& name, const TestOptionsPtr& options )
  : m_name(name)
  , m_options(options)
{}
