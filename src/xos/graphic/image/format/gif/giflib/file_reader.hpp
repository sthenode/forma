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
///   File: file_reader.hpp
///
/// Author: $author$
///   Date: 7/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_HPP

#include "xos/graphic/image/format/gif/giflib/file_reader_events.hpp"
#include "xos/graphic/image/format/gif/giflib/file.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/base/array.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace gif {
namespace giflib {

typedef giflib::file gif_file_t;
typedef arrayt<GifPixelType> gif_pixel_array_t;
typedef file_reader_events file_reader_implements;
typedef file_reader_events_extend file_reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: file_reader
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS file_reader
: virtual public file_reader_implements, public file_reader_extends {
public:
    typedef file_reader_implements implements;
    typedef file_reader_extends extends;

    file_reader(const char* file, file_reader_events* events = 0): extends(events), file_(file) {
    }
    file_reader(file_reader_events* events = 0): extends(events), file_(0) {
    }
    virtual ~file_reader() {
    }

    virtual bool read(const char* file) {
        if ((gif_file_.open(file))) {
            bool success = true;
            GifRecordType type = UNDEFINED_RECORD_TYPE;
            do {
                if (UNDEFINED_RECORD_TYPE != (type = gif_file_.GetRecordType())) {
                    if (!(success = this->OnGifRecordType(type))) {
                        break;
                    }
                }
            } while ((UNDEFINED_RECORD_TYPE != type) && (TERMINATE_RECORD_TYPE != type));
            gif_file_.close();
            return success;
        }
        return false;
    }
    virtual bool read() {
        return read(file_);
    }

protected:
    virtual bool OnGifRecordType(GifRecordType type) {
        bool success = true;
        switch(type) {
        case UNDEFINED_RECORD_TYPE:
            LOG_DEBUG("OnGif_UNDEFINED_RECORD_TYPE_RecordType(type = " << type << ")...");
            success = OnGif_UNDEFINED_RECORD_TYPE_RecordType(type);
            break;
            
        case SCREEN_DESC_RECORD_TYPE:
            LOG_DEBUG("OnGif_SCREEN_DESC_RECORD_TYPE_RecordType(type = " << type << ")...");
            success = OnGif_SCREEN_DESC_RECORD_TYPE_RecordType(type);
            break;
            
        case IMAGE_DESC_RECORD_TYPE:
            LOG_DEBUG("OnGif_IMAGE_DESC_RECORD_TYPE_RecordType(type = " << type << ")...");
            success = OnGif_IMAGE_DESC_RECORD_TYPE_RecordType(type);
            break;
            
        case EXTENSION_RECORD_TYPE:
            LOG_DEBUG("OnGif_EXTENSION_RECORD_TYPE_RecordType(type = " << type << ")...");
            success = OnGif_EXTENSION_RECORD_TYPE_RecordType(type);
            break;
            
        case TERMINATE_RECORD_TYPE:
            LOG_DEBUG("OnGif_TERMINATE_RECORD_TYPE_RecordType(type = " << type << ")...");
            success = OnGif_TERMINATE_RECORD_TYPE_RecordType(type);
            break;
            
        default:
            LOG_ERROR("...unexpected GifRecordType type = " << type << "")
            success = false;
        }
        return success;
    }
    virtual bool OnGif_UNDEFINED_RECORD_TYPE_RecordType(GifRecordType type) {
    bool success = true;
    return success;
    }
    virtual bool OnGif_SCREEN_DESC_RECORD_TYPE_RecordType(GifRecordType type) {
        bool success = true;
        return success;
    }
    virtual bool OnGif_IMAGE_DESC_RECORD_TYPE_RecordType(GifRecordType type) {
        bool success = true;
        GifImageDesc* image = 0;
        
        LOG_DEBUG("gif_file_.GetImageDesc()...");
        if ((image = gif_file_.GetImageDesc())) {
            ColorMapObject* colorMap = image->ColorMap;
            UINT interlaceType = image->Interlace;
            TSIZE width = image->Width;
            TSIZE height = image->Height;
            TSIZE colors = gif_file_.ColorResolution();
            GifPixelType backgroundPixel = gif_file_.BackGroundColor();

            if (!(colorMap)) {
                colorMap = gif_file_.ColorMap();
            }
            LOG_DEBUG("OnGifImage(height = " << height << ", width = " << width << ", colors = " << colors << ", interlaceType = " << interlaceType << ", backgroundPixel = " << backgroundPixel << ", colorMap = " << pointer_to_string(colorMap) << ")...");
            if (!(OnGifImage(height, width, colors, interlaceType, backgroundPixel, colorMap))) {
                success = false;
            }
        }
        return success;
    }
    virtual bool OnGif_EXTENSION_RECORD_TYPE_RecordType(GifRecordType type) {
        bool success = true;
        GifByteType* extBlock = 0;
        int extCode = 0;
        
        LOG_DEBUG("gif_file_.GetExtension(extCode)...");
        if ((extBlock = gif_file_.GetExtension(extCode))) {
            do {
                LOG_DEBUG("OnGifExtensionBlock(extCode = " << extCode << ", extBlock = " << pointer_to_string(extBlock) << ")");
                if (!(OnGifExtensionBlock(extCode, extBlock))) {
                    break;
                }
                LOG_DEBUG("gif_file_.GetExtensionNext()...");
                extBlock = gif_file_.GetExtensionNext();
            } while (extBlock);
        }
        return success;
    }
    virtual bool OnGif_TERMINATE_RECORD_TYPE_RecordType(GifRecordType type) {
        bool success = true;
        return success;
    }

    virtual bool OnGifExtensionBlock(int extCode, GifByteType* extBlock) {
        bool success = true;
        return success;
    }

protected:
    virtual bool OnGifImage
    (TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) {
        bool success = true;
        GifPixelType* pixels = 0;
        size_t pixelsSize = 0, pixelsLength = 0;
        
        LOG_DEBUG("OnBeginGifImage(height = " << height << ", width = " << width <<", ...)...");
        if (!(success = OnBeginGifImage
             (height, width, colors, interlaceType, backgroundPixel, colorMap))) {
            LOG_ERROR("...failed on OnBeginGifImage(height = " << height << ", width = " << width <<", ...)");
        } else {

            if ((width <= (gif_pixel_buffer_.set_size(width)))
                && ((width <= (gif_pixel_buffer_.set_length(width))))
                && (pixels = gif_pixel_buffer_.elements(pixelsSize, pixelsLength))) {
                TLENGTH count = 0;
                TSIZE line = 0;
                
                LOG_DEBUG("for (line = 0; line < " << height << "; ++line) {...");
                for (line = 0; line < height; ++line) {

                    LOG_TRACE("gif_file_.GetLine(pixels = " << pointer_to_string(pixels) << ", width = " << width << ")...");
                    if (width != (count = gif_file_.GetLine(pixels, width))) {
                        LOG_ERROR("...failed width = " << width << " != " << count << " = gif_file_.GetLine(pixels = " << pointer_to_string(pixels) << ", width = " << width << ")...");
                        success = false;
                        break;
                    }

                    LOG_TRACE("OnGifLine(pixels = " << pointer_to_string(pixels) << ", width = " << width << ", line = " << line << ", ...)...");
                    if (!(OnGifLine
                          (pixels, width, line, height, width, 
                           colors, interlaceType, backgroundPixel, colorMap))) {
                        LOG_ERROR("...failed on OnGifLine(pixels = " << pointer_to_string(pixels) << ", width = " << width << ", line = " << line << ", ...)");
                        success = false;
                        break;
                    }
                }
                LOG_DEBUG("...} for (...; " << line << " < " << height << ";...)");
            }

            LOG_DEBUG("OnEndGifImage(height = " << height << ", width = " << width <<", ...)...");
            if (!(OnEndGifImage
                  (height, width, colors, interlaceType, backgroundPixel, colorMap))) {
                LOG_ERROR("...failed on OnEndGifImage(height = " << height << ", width = " << width <<", ...)");
                success = false;
            }
        }
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
        
        LOG_TRACE("OnBeginGifLine(pixels, pixelsLength, pixelsLine, height, width, ...)...");
        if (!(success = OnBeginGifLine
              (pixels, pixelsLength, pixelsLine, height, width, 
               colors, interlaceType, backgroundPixel, colorMap))) {
            LOG_ERROR("...failed on OnBeginGifLine(pixels, pixelsLength, pixelsLine, height, width, ...)");
        } else {
            TSIZE pixelColumn = 0;

            LOG_TRACE("for (pixelColumn = 0; pixelColumn < pixelsLength; pixelColumn++) {...");
            for (pixelColumn = 0; pixelColumn < pixelsLength; pixelColumn++) {
                
                LOG_TRACE("OnGifColumn(pixels[pixelColumn = " << pixelColumn << "], pixelColumn = " << pixelColumn << ", pixelsLine = " << pixelsLine << ", ...)...");
                if (!(OnGifColumn
                      (pixels[pixelColumn], pixelColumn, pixelsLine,
                       height, width, colors, interlaceType, backgroundPixel, colorMap))) {
                    LOG_ERROR("...failed on OnGifColumn(pixels[pixelColumn = " << pixelColumn << "], pixelColumn = " << pixelColumn << ", pixelsLine = " << pixelsLine << ", ...)");
                    success = false;
                    break;
                }
            }
            LOG_TRACE("...} for (...; " << pixelColumn << " < " << pixelsLength << ";...)");

            LOG_TRACE("OnEndGifLine(pixels, pixelsLength, pixelsLine, height, width, ...)...");
            if (!(OnEndGifLine
                  (pixels, pixelsLength, pixelsLine, height, width, 
                   colors, interlaceType, backgroundPixel, colorMap))) {
                LOG_ERROR("...failed on OnEndGifLine(pixels, pixelsLength, pixelsLine, height, width, ...)");
                success = false;
            } else {
            }
        }
        return success;
    }
    virtual bool OnGifColumn
    (GifPixelType& pixel, 
     TSIZE pixelColumn, TSIZE pixelLine,
     TSIZE height, TSIZE width, 
     TSIZE colors, UINT interlaceType,
     GifPixelType backgroundPixel, 
     ColorMapObject* colorMap) {
        bool success = true;
        if ((colorMap) && (pixel < (colorMap->ColorCount))) {
            GifColorType color = colorMap->Colors[pixel];
            
            LOG_TRACE("OnGifPixelColor(color, pixel, pixelColumn, pixelLine, ...)...");
            if (!(success = OnGifPixelColor
                  (color, pixel, pixelColumn, pixelLine,
                   height, width, colors, interlaceType,
                   backgroundPixel, colorMap))) {
                LOG_ERROR("...failed on OnGifPixelColor(color, pixel, pixelColumn, pixelLine, ...)");
            }
        }
        return success;
    }
    
protected:
    const char* file_;
    gif_file_t gif_file_;
    gif_pixel_array_t gif_pixel_buffer_;
};

} /// namespace giflib
} /// namespace gif
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_READER_HPP 
