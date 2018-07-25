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
///   File: file_reader_events.hpp
///
/// Author: $author$
///   Date: 7/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_EVENTS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_EVENTS_HPP

#include "xos/graphic/image/format/gif/giflib/giflib.hpp"
#include "xos/graphic/image/format/pixel.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace gif {
namespace giflib {

typedef implement_base file_reader_eventst_implements;
///////////////////////////////////////////////////////////////////////
///  Class: file_reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = file_reader_eventst_implements>
class _EXPORT_CLASS file_reader_eventst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef format::pixel_t pixel_t;

    virtual bool OnGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnBeginGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnBeginGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnEndGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnEndGifImage
            (height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }

    virtual bool OnGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnBeginGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnBeginGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnEndGifLine
    (GifPixelType* pixels, 
     TSIZE pixelsLength, TSIZE pixelsLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnEndGifLine
            (pixels, pixelsLength, pixelsLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }

    virtual bool OnGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnBeginGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnBeginGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnEndGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnEndGifColumn
            (pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnGifPixelColor
    (GifColorType& color,GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnGifPixelColor
            (color, pixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }
    virtual bool OnGifPixel
    (pixel_t& pixel,
     GifColorType& color,GifPixelType& columnPixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) 
    {
        bool success = true;
        file_reader_eventst* forward_to = file_reader_events_forward_to();
        if ((forward_to))
            return forward_to->OnGifPixel
            (pixel, color, columnPixel, pixelColumn, pixelLine,
             height, width, colors, interlaceType,
             backgroundPixel, colorMap);
        return success;
    }

    virtual file_reader_eventst* forward_file_reader_events_to(file_reader_eventst* to) {
        return 0;
    }
    virtual file_reader_eventst* file_reader_events_forward_to() const {
        return 0;
    }
};
typedef file_reader_eventst<> file_reader_events;

///////////////////////////////////////////////////////////////////////
///  Class: file_reader_events_extendt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = file_reader_events, class TExtends = base>
class _EXPORT_CLASS file_reader_events_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements file_reader_events_t;

    file_reader_events_extendt(file_reader_events_t* file_reader_events_forward_to = 0)
    : file_reader_events_forward_to_(file_reader_events_forward_to) {
    }
    virtual ~file_reader_events_extendt() {
    }

    virtual file_reader_events_t* forward_file_reader_events_to(file_reader_events_t* to) {
        file_reader_events_forward_to_ = to;
        return file_reader_events_forward_to_;
    }
    virtual file_reader_events_t* file_reader_events_forward_to() const {
        return file_reader_events_forward_to_;
    }

protected:
    file_reader_events_t* file_reader_events_forward_to_;
};
typedef file_reader_events_extendt<> file_reader_events_extend;

} /// namespace giflib
} /// namespace gif
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_EVENTS_HPP 
