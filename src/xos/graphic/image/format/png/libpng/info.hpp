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
///   File: info.hpp
///
/// Author: $author$
///   Date: 7/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_HPP

#include "xos/graphic/image/format/png/libpng/info_created.hpp"
#include "xos/graphic/image/format/png/libpng/palette.hpp"
#include "xos/graphic/image/format/png/libpng/color.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef info_created_implements info_implements;
typedef info_created info_extends;
///////////////////////////////////////////////////////////////////////
///  Class: infot
///////////////////////////////////////////////////////////////////////
template
<class TImplements = info_implements, class TExtends = info_extends>
class _EXPORT_CLASS infot: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::attached_t attached_t;
    typedef struct_created struct_created_t;

    infot
    (struct_created_t& struct_created,
     attached_t detached = 0, bool is_created = false)
    : extends(struct_created, detached, is_created),
      colorPalette_(struct_created, *this),
      imageRow_(0), imageRows_(0), imageRowsPerRead_(1) {
    }
    virtual ~infot() {
    }

    virtual bool destroy() {
        bool success = true;
        if (!(FreedImageRows())) {
            success = false;
        }
        if (!(extends::destroy())) {
            success = false;
        }
        return success;
    }

    virtual png_int_32 Read() {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_int_32 count = 0, readCount = 0;
                png_uint_32 oldBytesRead = 0, rows = 0, rowBytes = 0;
                int colorType = 0, bitDepth = 0, channels = 0, paletteColors = 0;

                try {
                    if (0 < (count = ReadInfo
                        (rows, rowBytes, colorType, bitDepth, channels, paletteColors))) {
                        // Allocate the memory to hold the image rows.
                        //
                        if ((imageRow_ = AllocateImageRows(rowBytes, rows))) {
                            imageRows_ = rows;
                            oldBytesRead = this->struct_created_.SetBytesRead(0);

                            // Read the image all at once
                            //
                            try {
                                LOG_DEBUG("png_read_image()...");
                                png_read_image(struct_detached, imageRow_);
                                LOG_DEBUG("...png_read_image()");
                            } catch (const error_string& e) {
                                LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                            }

                            if (0 < (readCount = this->struct_created_.SetBytesRead(oldBytesRead))) {
                                count += readCount;
                                if (0 < (readCount = ReadEnd())) {
                                    count += readCount;
                                    return count;
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } catch (const error_string& e) {
                    LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                }
            } else {
            }
        } else {
        }
        return 0;
    }
    virtual png_int_32 ReadBegin(png_int_32 rowsPerRead = 0) {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_int_32 count = 0;
                png_uint_32 rows = 0, rowBytes = 0;
                int colorType = 0, bitDepth = 0, channels = 0, paletteColors = 0;

                try {
                    if (0 < (count = ReadInfo
                        (rows, rowBytes, colorType, bitDepth, channels, paletteColors))) {
                        if (0 > (rowsPerRead)) {
                            rowsPerRead = rows;
                        } else {
                            if (1 > (rowsPerRead)) {
                                rowsPerRead = rows;
                            } else {
                                rowsPerRead = ImageRowsPerRead();
                            }
                        }
                        if (0 <  (rowsPerRead)) {
                            // Allocate the memory to hold the image rows.
                            //
                            if ((imageRow_ = AllocateImageRows(rowBytes, rowsPerRead))) {
                                imageRows_ = rowsPerRead;
                                return count;
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } catch (const error_string& e) {
                    LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                }
            } else {
            }
        } else {
        }
        return 0;
    }
    virtual png_int_32 ReadEnd() {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_uint_32 oldBytesRead = 0;
                png_int_32 count = 0;

                oldBytesRead = this->struct_created_.SetBytesRead(0);

                // read rest of file, and get additional chunks in info_ptr
                //
                try {
                    LOG_DEBUG("png_read_end()...");
                    png_read_end(struct_detached, detached);
                    LOG_DEBUG("...png_read_end()");
                } catch (const error_string& e) {
                    LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                }

                if (0 < (count = this->struct_created_.SetBytesRead(oldBytesRead))) {
                    return count;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual png_int_32 ReadInfo
    (png_uint_32& rows, png_uint_32& rowBytes,
     int& colorType, int& bitDepth, int& channels, int& paletteColors) {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_uint_32 oldBytesRead = 0;
                png_int_32 count = 0;

                oldBytesRead = this->struct_created_.SetBytesRead(0);

                // The call to png_read_info() gives all of the information from the
                // PNG file before the first IDAT (image data chunk).
                //
                try {
                    LOG_DEBUG("png_read_info()...");
                    png_read_info(struct_detached, detached);
                    LOG_DEBUG("...png_read_info()");
                } catch (const error_string& e) {
                    LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                }

                if (0 < (count = this->struct_created_.SetBytesRead(oldBytesRead))) {
                    if (0 < (rows = this->ImageHeight())) {
                        if (0 < (rowBytes = this->RowBytes())) {
                            if (0 < (bitDepth = this->BitDepth())) {
                                if (0 < (colorType = this->ColorType())) {
                                    if (0 < (channels = this->Channels())) {
                                        if (PNG_COLOR_MASK_PALETTE != (PNG_COLOR_MASK_PALETTE & colorType)) {
                                            paletteColors = 0;
                                            return count;
                                        } else {
                                            if (0 < (paletteColors = this->colorPalette_.colors())) {
                                                return count;
                                            } else {
                                            }
                                        }
                                    } else {
                                    }
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual png_int_32 ReadRows() {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                if ((imageRow_) && (imageRows_)) {
                    png_uint_32 oldBytesRead = 0;
                    png_int_32 count = 0;

                    oldBytesRead = this->struct_created_.SetBytesRead(0);

                    // Read imageRows_ rows at a time
                    //
                    try {
                        LOG_TRACE("png_read_rows()...");
                        png_read_rows(struct_detached, imageRow_, NULL, imageRows_);
                        LOG_TRACE("...png_read_rows()");
                        count = this->struct_created_.SetBytesRead(oldBytesRead);
                        return count;
                    } catch (const error_string& e) {
                        LOG_ERROR("...caught const error_string& e = \"" << e << "\"");
                        this->struct_created_.SetBytesRead(oldBytesRead);
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return -1;
    }

    virtual bool FreedImageRows() {
        if ((imageRow_) && (imageRows_)) {
            bool success = FreeImageRows(imageRow_, imageRows_);
            imageRow_ = 0;
            imageRows_ = 0;
            return success;
        } else {
        }
        return true;
    }

    virtual png_bytep* AllocateImageRows(png_uint_32 rowBytes, png_uint_32 rows) {
        if ((rowBytes) && (rows)) {
            png_bytep* imageRows = 0;

            if ((imageRows = new png_bytep[rows])) {
                for (png_uint_32 row = 0; row < rows; row++) {
                    if ((imageRows[row] = AllocateImageRow(rowBytes))) {
                        continue;
                    }
                    for (row++; row > 0; ) {
                        FreeImageRow(imageRows[--row]);
                    }
                    delete[] imageRows;
                    return 0;
                }
                return imageRows;
            }
        }
        return 0;
    }
    virtual bool FreeImageRows(png_bytep* imageRow, png_uint_32 imageRows) {
        png_bytep* imageRowBytes = 0;

        if ((imageRowBytes = imageRow)) {
            for (png_uint_32 row = imageRows; row; --row, ++imageRowBytes) {
                png_bytep rowBytes = 0;
                if ((rowBytes = *imageRowBytes)) {
                    if ((FreeImageRow(rowBytes))) {
                        continue;
                    }
                }
                return false;
            }
            delete[] imageRow;
            return true;
        }
        return false;
    }

    virtual png_bytep AllocateImageRow(png_uint_32 rowBytes) {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_bytep imageRow = 0;
                LOG_TRACE("png_malloc(struct_detached, rowBytes = " << rowBytes << ")...");
                if ((imageRow = (png_bytep)png_malloc(struct_detached, rowBytes))) {
                    LOG_TRACE("...png_malloc(struct_detached, rowBytes = " << rowBytes << ")");
                    return imageRow;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }
    virtual bool FreeImageRow(png_bytep imageRow) {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                LOG_TRACE("png_free(struct_detached, imageRow)...");
                png_free(struct_detached, imageRow);
                LOG_TRACE("...png_free(struct_detached, imageRow)");
                return true;
            } else {
            }
        } else {
        }
        return false;
    }

    virtual png_int_32 SetImageHeight(png_int_32 to) {
        return 0;
    }
    virtual png_int_32 ImageHeight() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_int_32 to = 0;
                LOG_DEBUG("png_get_image_height(struct_detached, detached)...");
                if (0 < (to = png_get_image_height(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_image_height(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual png_int_32 SetImageWidth(png_int_32 to) {
        return 0;
    }
    virtual png_int_32 ImageWidth() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                png_int_32 to = 0;
                LOG_DEBUG("png_get_image_width(struct_detached, detached)...");
                if (0 < (to = png_get_image_width(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_image_width(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetBitDepth(int to) {
        return 0;
    }
    virtual int BitDepth() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_bit_depth(struct_detached, detached)...");
                if (0 < (to = png_get_bit_depth(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_bit_depth(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetColorType(int to) {
        return 0;
    }
    virtual int ColorType() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_color_type(struct_detached, detached)...");
                if (0 <= (to = png_get_color_type(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_color_type(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetChannels(int to) {
        return 0;
    }
    virtual int Channels() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_channels(struct_detached, detached)...");
                if (0 < (to = png_get_channels(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_channels(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetFilterType(int to) {
        return 0;
    }
    virtual int FilterType() const {
        attached_t detached = 0;

        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;

            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_filter_type(struct_detached, detached)...");
                if (0 <= (to = png_get_filter_type(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_filter_type(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetInterlaceType(int to) {
        return 0;
    }
    virtual int InterlaceType() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;
            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_interlace_type(struct_detached, detached)...");
                if (0 <= (to = png_get_interlace_type(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_interlace_type(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual int SetCompressionType(int to) {
        return 0;
    }
    virtual int CompressionType() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;
            if ((struct_detached = this->struct_created_.attached_to())) {
                int to = 0;
                LOG_DEBUG("png_get_compression_type(struct_detached, detached)...");
                if (0 <= (to = png_get_compression_type(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_compression_type(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual png_uint_32 SetRowBytes(png_uint_32 to) {
        return 0;
    }
    virtual png_uint_32 RowBytes() const {
        attached_t detached = 0;
        if ((detached = this->attached_to())) {
            struct_attached_t struct_detached = 0;
            if ((struct_detached = this->struct_created_.attached_to())) {
                png_uint_32 to = 0;
                LOG_DEBUG("png_get_rowbytes(struct_detached, detached)...");
                if (0 < (to = png_get_rowbytes(struct_detached, detached))) {
                    LOG_DEBUG("..." << to << " = png_get_rowbytes(struct_detached, detached)");
                    return to;
                } else {
                }
            } else {
            }
        } else {
        }
        return 0;
    }

    virtual png_bytep* ImageRow
    (png_uint_32& imageRows, png_uint_32& rowBytes) const {
        rowBytes = RowBytes();
        imageRows = imageRows_;
        return imageRow_;
    }

    virtual png_uint_32 SetImageRows(png_uint_32 to) {
        imageRows_ = to;
        return imageRows_;
    }
    virtual png_uint_32 ImageRows() const {
        return imageRows_;
    }
    virtual png_uint_32 SetImageRowsPerRead(png_uint_32 to) {
        imageRowsPerRead_ = to;
        return imageRowsPerRead_;
    }
    virtual png_uint_32 ImageRowsPerRead() const {
        return imageRowsPerRead_;
    }

protected:
    palette colorPalette_;
    png_bytep* imageRow_;
    png_uint_32 imageRows_, imageRowsPerRead_;
};
typedef infot<> info;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_HPP 
