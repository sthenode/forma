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
///   File: reader_events.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_EVENTS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_EVENTS_HPP

#include "xos/graphic/image/format/png/libpng/png.hpp"
#include "xos/graphic/image/format/pixel.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = implement_base>
class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef format::pixel_t pixel_t;

    virtual bool on_PNGPixel8
    (pixel_t& pixel, byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_PNGPixel8(" << p_to_string(&pixel) << "," << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_PNGPixel8(pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_PNGPixel8(" << p_to_string(&pixel) << "," << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }
    virtual bool on_PNGPixel16
    (pixel_t& pixel, byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_PNGPixel16(" << p_to_string(&pixel) << "," << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_PNGPixel16(pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_PNGPixel16(" << p_to_string(&pixel) << "," << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }

    virtual bool on_PNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_PNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_PNGCol(colByte, colBytes, col, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_PNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }

    virtual bool on_PNGRow
    (byte_t* rowByte, size_t rowBytes, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_PNGRow(rowByte, rowBytes, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }
    virtual bool on_begin_PNGRow
    (byte_t* rowByte, size_t rowBytes, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_begin_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_begin_PNGRow(rowByte, rowBytes, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_begin_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }
    virtual bool on_end_PNGRow
    (byte_t* rowByte, size_t rowBytes, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_TRACE("on_end_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_end_PNGRow(rowByte, rowBytes, row, height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_end_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }

    virtual bool on_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_DEBUG("on_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_PNGImage(height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_DEBUG("...on_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }
    virtual bool on_begin_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_DEBUG("on_begin_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_begin_PNGImage(height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_DEBUG("...on_begin_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }
    virtual bool on_end_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        reader_eventst* forward_to = png_reader_events_forward_to();
        LOG_DEBUG("on_end_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((forward_to)) {
            return forward_to->on_end_PNGImage(height, width, bitDepth, colorChannels, colorType, filterType, interlaceType, compressionType);
        }
        LOG_DEBUG("...on_end_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return true;
    }

    virtual reader_eventst* forward_png_reader_events_to(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* png_reader_events_forward_to() const {
        return 0;
    }
};
typedef reader_eventst<> reader_events;

///////////////////////////////////////////////////////////////////////
///  Class: reader_events_extendt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_events, class TExtends = base>

class _EXPORT_CLASS reader_events_extendt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements reader_events_t;

    reader_events_extendt
    (reader_events_t* reader_events_forward_to = 0)
    : reader_events_forward_to_(reader_events_forward_to) {
    }
    virtual ~reader_events_extendt() {
    }

    virtual reader_events_t* forward_png_reader_events_to(reader_events_t* to) {
        reader_events_forward_to_ = to;
        return reader_events_forward_to_;
    }
    virtual reader_events_t* png_reader_events_forward_to() const {
        return reader_events_forward_to_;
    }

protected:
    reader_events_t* reader_events_forward_to_;
};
typedef reader_events_extendt<> reader_events_extend;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_EVENTS_HPP 
