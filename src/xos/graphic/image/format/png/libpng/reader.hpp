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
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_HPP

#include "xos/graphic/image/format/png/libpng/reader_events.hpp"
#include "xos/graphic/image/format/png/libpng/info_reader.hpp"
#include "xos/graphic/image/format/png/libpng/read_struct.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = reader_events, class TExtends = reader_events_extend>
class _EXPORT_CLASS readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef readert derives;

    typedef implements reader_events_t;
    typedef read_struct read_struct_t;
    typedef info_reader info_reader_t;
    typedef xos::io::byte_reader byte_reader_t;

    typedef format::rgb::pixel_t rgb_pixel_t;
    typedef format::rgba::pixel_t rgba_pixel_t;

    readert
    (byte_reader_t& in, reader_events_t* reader_events_forward_to = 0)
    : extends(reader_events_forward_to),
      read_struct_(in, 0, false), info_reader_(read_struct_, 0, false),
      on_PNGCol_(0), colBytes_(0), bytesRead_(0) {
    }
    virtual ~readert() {
    }

    virtual ssize_t read() {
        if ((info_reader_.create())) {
            size_t count = read(info_reader_);
            info_reader_.destroy();
            return count;
        }
        return 0;
    }

protected:
    virtual bool on_8BitPalettePNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = false;
        LOG_ERROR("...unimplemented on_8BitPalettePNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }
    virtual bool on_16BitPalettePNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = false;
        LOG_ERROR("...unimplemented on_6BitPalettePNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

    virtual bool on_8BitRGBPNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        rgb_pixel_t pixel(colByte[0], colByte[1], colByte[2], ((byte_t)-1));
        bool success = this->on_PNGPixel8
        (pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        //LOG_ERROR("...unimplemented on_8BitRGBPNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }
    virtual bool on_16BitRGBPNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        word_t* colWord = ((word_t*)colByte);
        rgb_pixel_t pixel(colWord[0], colWord[1], colWord[2], ((word_t)-1));
        bool success = this->on_PNGPixel8
        (pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        //LOG_ERROR("...unimplemented on_16BitRGBPNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

    virtual bool on_8BitRGBAPNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        rgba_pixel_t pixel(colByte[0], colByte[1], colByte[2], colByte[3], ((byte_t)-1));
        bool success = this->on_PNGPixel8
        (pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        //LOG_ERROR("...unimplemented on_BitRGBAPNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }
    virtual bool on_16BitRGBAPNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        word_t* colWord = ((word_t*)colByte);
        rgba_pixel_t pixel(colWord[0], colWord[1], colWord[2], colWord[2], ((word_t)-1));
        bool success = this->on_PNGPixel8
        (pixel, colByte, colBytes, col, row, height, width, bitDepth, colorChannels,
         colorType, filterType, interlaceType, compressionType);
        //LOG_ERROR("...unimplemented on_16BitRGBAPNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

    virtual bool on_PNGCol
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = true;
        LOG_TRACE("on_PNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((this->on_PNGCol_)) {
            success = (this->*on_PNGCol_)
            (colByte, colBytes, col, row, height, width, bitDepth, colorChannels,
             colorType, filterType, interlaceType, compressionType);
        }
        LOG_TRACE("...on_PNGCol(" << p_to_string(colByte) << "," <<  colBytes << "," <<  col << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

    virtual bool on_PNGRow
    (byte_t* rowByte, size_t rowBytes, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = true;
        LOG_TRACE("on_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((success = this->on_begin_PNGRow
             (rowByte, rowBytes, row, height, width, bitDepth, colorChannels,
              colorType, filterType, interlaceType, compressionType))) {
            byte_t* colByte = 0;
            size_t col = 0;

            for (colByte = rowByte, col = 0;
                 col < width; ++col, colByte += colBytes_) {
                if (!(this->on_PNGCol
                    (colByte, colBytes_, col, row, height, width, bitDepth, colorChannels,
                     colorType, filterType, interlaceType, compressionType))) {
                    success = false;
                    break;
                }
            }

            if (!(this->on_end_PNGRow
                 (rowByte, rowBytes, row, height, width, bitDepth, colorChannels,
                  colorType, filterType, interlaceType, compressionType))) {
                success = false;
            } else {}
        } else {}
        LOG_TRACE("...on_PNGRow(" << p_to_string(rowByte) << "," <<  rowBytes << "," <<  row << "," <<  height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

    virtual bool on_PNGColorType
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = true;

        switch(colorType) {

        case PNG_COLOR_TYPE_RGB:
            switch(bitDepth) {
            case 8:
                on_PNGCol_ = &derives::on_8BitRGBPNGCol;
                break;
            case 16:
                on_PNGCol_ = &derives::on_16BitRGBPNGCol;
                break;
            default:
                success = false;
                LOG_DEBUG("...unimplemented bitDepth = " << bitDepth << " on_PNGColorType(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
                break;
            }
            break;

        case PNG_COLOR_TYPE_RGB_ALPHA:
            switch(bitDepth) {
            case 8:
                on_PNGCol_ = &derives::on_8BitRGBAPNGCol;
                break;
            case 16:
                on_PNGCol_ = &derives::on_16BitRGBAPNGCol;
                break;
            default:
                success = false;
                LOG_DEBUG("...unimplemented bitDepth = " << bitDepth << " on_PNGColorType(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
                break;
            }
            break;

        case PNG_COLOR_TYPE_PALETTE:
            switch(bitDepth) {
            case 8:
                on_PNGCol_ = &derives::on_8BitPalettePNGCol;
                break;
            case 16:
                on_PNGCol_ = &derives::on_16BitPalettePNGCol;
                break;
            default:
                success = false;
                LOG_DEBUG("...unimplemented bitDepth = " << bitDepth << " on_PNGColorType(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
                break;
            }
            break;
        default:
            success = false;
            LOG_DEBUG("...unimplemented colorType = " << colorType << " on_PNGColorType(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
            break;
        }
        return success;
    }

    virtual bool on_PNGImage
    (size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType) {
        bool success = true;
        LOG_DEBUG("on_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")...");
        if ((success = this->on_PNGColorType
             (height, width, bitDepth, colorChannels,
              colorType, filterType, interlaceType, compressionType))) {

            if ((success = this->on_begin_PNGImage
                 (height, width, bitDepth, colorChannels,
                  colorType, filterType, interlaceType, compressionType))) {
                png_bytep *imageRow = 0, rowByte = 0;
                png_uint_32 imageRows = 0, rowBytes = 0, rowIndex = 0, row = 0;
                png_int_32 count = 0;

                colBytes_ = ((bitDepth + 7) / 8) * colorChannels;

                if ((imageRow = info_reader_.ImageRow(imageRows, rowBytes))) {
                    if ((0 < (imageRows)) && (0 < (rowBytes))) {
                        for (row = 0; row < height; row += imageRows) {
                            if (0 <= (count = info_reader_.ReadRows())) {

                                bytesRead_ += count;

                                for (rowByte = imageRow[rowIndex = 0];
                                     rowIndex < imageRows; rowByte = imageRow[++rowIndex]) {

                                    if (!(this->on_PNGRow
                                        (rowByte, rowBytes, row, height, width, bitDepth, colorChannels,
                                         colorType, filterType, interlaceType, compressionType))) {
                                        success = false;
                                        break;
                                    }
                                }
                                if (!(success)) {
                                    break;
                                }
                            } else {
                                success = false;
                                break;
                            }
                        }
                    } else {}
                } else {}

                if (!(this->on_end_PNGImage
                     (height, width, bitDepth, colorChannels,
                      colorType, filterType, interlaceType, compressionType))) {
                    success = false;
                }
            }
        }
        LOG_DEBUG("...on_PNGImage(" << height << "," <<  width << "," <<  bitDepth << "," <<  colorChannels << "," <<  colorType << "," <<  filterType << "," <<  interlaceType << "," <<  compressionType << ")");
        return success;
    }

protected:
    virtual ssize_t read(info_reader_t& info_reader, png_int_32 rowsPerRead = 1) {
        size_t height = 0, width = 0, bitDepth = 0, channels = 0;
        uint colorType = 0, filterType = 0, interlaceType = 0, compressionType = 0;
        png_int_32 value = 0;

        if (0 < (value = (bytesRead_ = info_reader_.ReadBegin(rowsPerRead)))) {
            if (0 < (value = info_reader_.ImageHeight())) {
                height = value;
                if (0 < (value = info_reader_.ImageWidth())) {
                    width = value;
                    if (0 < (value = info_reader_.BitDepth())) {
                        bitDepth = value;
                        if (0 < (value = info_reader_.Channels())) {
                            channels = value;
                            if (0 <= (value = info_reader_.ColorType())) {
                                colorType = value;
                                if (0 <= (value = info_reader_.FilterType())) {
                                    filterType = value;
                                    if (0 <= (value = info_reader_.InterlaceType())) {
                                        interlaceType = value;
                                        if (0 <= (value = info_reader_.CompressionType())) {
                                            compressionType = value;
                                            if ((this->on_PNGImage
                                                (height, width, bitDepth, channels,
                                                 colorType, filterType, interlaceType, compressionType))) {
                                                if (0 <= (value = info_reader_.ReadEnd())) {
                                                    return bytesRead_;
                                                } else {}
                                            } else {}
                                        } else {}
                                    } else {}
                                } else {}
                            } else {}
                        } else {}
                    } else {}
                } else {}
            } else {}
        } else {}
        return 0;
    }

protected:
    typedef bool (derives::*on_PNGCol_t)
    (byte_t* colByte, size_t colBytes, size_t col, size_t row,
     size_t height, size_t width, size_t bitDepth, size_t colorChannels,
     uint colorType, uint filterType, uint interlaceType, uint compressionType);

    read_struct_t read_struct_;
    info_reader_t info_reader_;
    on_PNGCol_t on_PNGCol_;
    size_t colBytes_;
    png_int_32 bytesRead_;
};
typedef readert<> reader;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READER_HPP 
