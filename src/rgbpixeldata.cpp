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

RGBPixelData RGBPixelData::rotate90() const
{
    std::vector<unsigned char> res(3*m_Height*m_Width, 0);

    for (size_t y = 0; y < m_Height; y++) {
        for (size_t x = 0; x < m_Width; x++) {
            for (size_t c = 0; c < 3; c++) {
                size_t p0 = 3*(y*m_Width + x) + c;
                size_t xnew = y;
                size_t ynew = m_Width-1-x;
                size_t p90 = 3*(ynew*m_Height + xnew) + c;
                res.at(p90) = m_Data.at(p0);
            }
        }
    }

    return RGBPixelData(m_Height, m_Width, 3*m_Height, res);
}

RGBPixelData RGBPixelData::rotate180() const
{
    std::vector<unsigned char> res(3*m_Width*m_Height, 0);

    for (size_t y = 0; y < m_Height; y++) {
        for (size_t x = 0; x < m_Width; x++) {
            for (size_t c = 0; c < 3; c++) {
                size_t p0 = 3*(y*m_Width + x) + c;
                size_t xnew = m_Width-1-x;
                size_t ynew = m_Height-1-y;
                size_t p180 = 3*(ynew*m_Width + xnew) + c;
                res.at(p180) = m_Data.at(p0);
            }
        }
    }

    return RGBPixelData(m_Width, m_Height, 3*m_Width, res);
}

RGBPixelData RGBPixelData::rotate270() const
{
    std::vector<unsigned char> res(3*m_Height*m_Width, 0);

    for (size_t y = 0; y < m_Height; y++) {
        for (size_t x = 0; x < m_Width; x++) {
            for (size_t c = 0; c < 3; c++) {
                size_t p0 = 3*(y*m_Width + x) + c;
                size_t xnew = m_Height-1-y;
                size_t ynew = x;
                size_t p270 = 3*(ynew*m_Height + xnew) + c;
                res.at(p270) = m_Data.at(p0);
            }
        }
    }

    return RGBPixelData(m_Height, m_Width, 3*m_Height, res);
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
