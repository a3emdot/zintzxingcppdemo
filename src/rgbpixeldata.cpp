#include "rgbpixeldata.h"

#include <iomanip>
#include <fstream>

RGBPixelData::RGBPixelData(
    unsigned int width,
    unsigned int height,
    unsigned int stride,
    const std::vector<unsigned char>& data
)
    : m_Width(width)
    , m_Height(height)
    , m_Stride(stride)
    , m_Data(data)
{}

unsigned int
RGBPixelData::width() const
{
    return m_Width;
}

unsigned int
RGBPixelData::height() const
{
    return m_Height;
}

unsigned int
RGBPixelData::stride() const
{
    return m_Stride;
}

const std::vector<unsigned char>&
RGBPixelData::data() const
{
    return m_Data;
}

void
RGBPixelData::savePPMAscii( const std::string& filename ) const
{
    std::ofstream ofs(filename);
    if (!ofs.good()) {
        std::string s;
        s += "Error with file ";
        s += "'";
        s += filename;
        s += "'";
        throw std::runtime_error(s);
    }

    ofs << "P3" << std::endl;
    ofs << m_Width << " " << m_Height << std::endl;
    ofs << "255" << std::endl;
    for (size_t z = 0, y = 0; y < m_Height; y++) {
        for (size_t x = 0; x < m_Width; x++) {
            for (size_t c = 0; c < 3; c++, z++) {
                ofs << std::setw(3) << static_cast<unsigned int>(m_Data.at(z)) << " ";
            }
            ofs << "# " << x << " " << y << std::endl;
        }
    }
}
