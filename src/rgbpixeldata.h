#pragma once

#include <string>
#include <vector>

class RGBPixelData
{
public:
    RGBPixelData(
        unsigned int width = 0,
        unsigned int height = 0,
        unsigned int stride = 0,
        const std::vector<unsigned char>& data = {}
    );

    unsigned int width() const;
    unsigned int height() const;
    unsigned int stride() const;
    const std::vector<unsigned char>& data() const;

    void savePPMAscii( const std::string& filename ) const;

    RGBPixelData rotate90() const;
    RGBPixelData rotate180() const;
    RGBPixelData rotate270() const;

private:
    unsigned int m_Width;
    unsigned int m_Height;
    unsigned int m_Stride;
    std::vector<unsigned char> m_Data;
};

