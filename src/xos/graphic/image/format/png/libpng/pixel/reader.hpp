///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: reader.hpp
///
/// Author: $author$
///   Date: 7/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PIXEL_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PIXEL_READER_HPP

#include "xos/graphic/image/format/png/libpng/reader.hpp"
#include "xos/graphic/image/format/pixel/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: reader_implementst
///////////////////////////////////////////////////////////////////////
template 
<class TEventsImplements = libpng::reader_events, 
 class TImplements = format::pixel::reader>

class _EXPORT_CLASS reader_implementst
: virtual public TEventsImplements, virtual public TImplements {
public:
    typedef TEventsImplements events_implements;
    typedef TImplements implements;

    typedef typename events_implements::pixel_t pixel_t;
    typedef typename implements::rgba_pixel_t rgba_pixel_t;
    typedef typename implements::pixel_value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = implements::pixel_value_interpretation_none,
        pixel_value_interpretation_greyscale = implements::pixel_value_interpretation_greyscale,
        pixel_value_interpretation_rgb = implements::pixel_value_interpretation_rgb,
        pixel_value_interpretation_rgba = implements::pixel_value_interpretation_rgba,
    };
};
typedef reader_implementst<> reader_implements;

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_implements, class TExtends = base>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef readert derives;

    typedef typename implements::rgba_pixel_t rgba_pixel_t;
    typedef typename implements::pixel_t pixel_t;
    typedef typename implements::pixel_value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = implements::pixel_value_interpretation_none,
        pixel_value_interpretation_greyscale = implements::pixel_value_interpretation_greyscale,
        pixel_value_interpretation_rgb = implements::pixel_value_interpretation_rgb,
        pixel_value_interpretation_rgba = implements::pixel_value_interpretation_rgba,
    };

    readert(io::byte_reader& in)
    : reader_(in, this),
      pixel_value_interpretation_(pixel_value_interpretation_none),
      on_PNGPixel_(0) {
    }
    virtual ~readert() {
    }

    virtual bool read() {
        if ((reader_.read())) {
            return true;
        }
        return false;
    }

    virtual bool on_PNGPixel8
    (pixel_t& pixel,
     byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        size_t red = pixel.red(), green = pixel.green(), blue = pixel.blue();
        rgba_pixel_t pix(red, green, blue, ((byte_t)-1), ((byte_t)-1));
        bool success = this->on_image_pixel
        (pix, colByte, colBytes, col, row, 0, width, height, 1,
         colorChannels, bitDepth, pixel_value_interpretation_);
        return success;
    }
    virtual bool on_PNGPixel16
    (pixel_t& pixel,
     byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        size_t red = pixel.red(), green = pixel.green(), blue = pixel.blue(), alpha = pixel.alpha();
        rgba_pixel_t pix(red, green, blue, alpha, ((word_t)-1));
        bool success = this->on_image_pixel
        (pix, colByte, colBytes, col, row, 0, width, height, 1,
         colorChannels, bitDepth, pixel_value_interpretation_);
        return success;
    }

    virtual bool on_begin_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = true;

        switch (interlaceType) {

        case PNG_INTERLACE_NONE:
            switch (colorType) {
            case PNG_COLOR_TYPE_RGB:
            case PNG_COLOR_TYPE_RGB_ALPHA:
                pixel_value_interpretation_ = (PNG_COLOR_TYPE_RGB_ALPHA != colorType)
                ?(pixel_value_interpretation_rgb):(pixel_value_interpretation_rgba);
                success = this->on_begin_image
                (width, height, 1, colorChannels, bitDepth, pixel_value_interpretation_);
                break;

            default:
                success = false;
                LOG_ERROR("...unimplemented colorType = " << colorType << " on_begin_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
                break;
            }
            break;

        default:
            success = false;
            LOG_ERROR("...unimplemented interlaceType = " << interlaceType << " on_begin_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
            break;
        }
        return success;
    }
    virtual bool on_end_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = this->on_end_image
        (width, height, 1, colorChannels, bitDepth, pixel_value_interpretation_);
        return success;
    }

protected:
    libpng::reader reader_;
    pixel_value_interpretation_t pixel_value_interpretation_;
    bool (derives::*on_PNGPixel_)
    (pixel_t& pixel,
     byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType);
};
typedef readert<> reader;

} /// namespace pixel
} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PIXEL_READER_HPP 
