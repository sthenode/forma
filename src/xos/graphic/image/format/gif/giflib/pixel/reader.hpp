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
///   Date: 7/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_READER_HPP

#include "xos/graphic/image/format/gif/giflib/file_reader.hpp"
#include "xos/graphic/image/format/pixel/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace gif {
namespace giflib {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: reader_implementst
///////////////////////////////////////////////////////////////////////
template 
<class TEventsImplements = giflib::file_reader_events, 
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

    readert(const char* file)
    : reader_(file, this),
      pixel_value_interpretation_(pixel_value_interpretation_none),
      OnGifPixel_(0) {
    }
    readert()
    : reader_(this),
      pixel_value_interpretation_(pixel_value_interpretation_none),
      OnGifPixel_(0) {
    }
    virtual ~readert() {
    }

    virtual bool read(const char* file) {
        if ((reader_.read(file))) {
            return true;
        }
        return false;
    }
    virtual bool read() {
        if ((reader_.read())) {
            return true;
        }
        return false;
    }

protected:
    giflib::file_reader reader_;
    pixel_value_interpretation_t pixel_value_interpretation_;
    bool (derives::*OnGifPixel_)
    (pixel_t& pixel,
     GifColorType& color,GifPixelType& columnPixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap);
};
typedef readert<> reader;

} /// namespace pixel
} /// namespace giflib
} /// namespace gif
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_READER_HPP 
