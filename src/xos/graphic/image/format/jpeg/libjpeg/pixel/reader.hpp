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
///   Date: 7/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_PIXEL_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_PIXEL_READER_HPP

#include "xos/graphic/image/format/jpeg/libjpeg/reader.hpp"
#include "xos/graphic/image/format/pixel/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace jpeg {
namespace libjpeg {
namespace pixel {

typedef libjpeg::reader_events reader_events_implements;
typedef format::pixel::reader reader_reader_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_implements
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader_implements
: virtual public reader_events_implements, virtual public reader_reader_implements {
public:
    typedef reader_events_implements events_implements;
    typedef reader_reader_implements implements;

    typedef typename implements::rgba_pixel_t rgba_pixel_t;
    typedef typename implements::pixel_value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = implements::pixel_value_interpretation_none,
        pixel_value_interpretation_greyscale = implements::pixel_value_interpretation_greyscale,
        pixel_value_interpretation_rgb = implements::pixel_value_interpretation_rgb,
        pixel_value_interpretation_rgba = implements::pixel_value_interpretation_rgba,
        pixel_value_interpretation_palette = implements::pixel_value_interpretation_palette,
    };
};
typedef base reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: reader
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader: virtual public reader_implements, public reader_extends {
public:
    typedef reader_implements implements;
    typedef reader_extends extends;
    typedef reader derives;

    typedef typename implements::rgba_pixel_t rgba_pixel_t;
    typedef typename implements::pixel_value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = implements::pixel_value_interpretation_none,
        pixel_value_interpretation_greyscale = implements::pixel_value_interpretation_greyscale,
        pixel_value_interpretation_rgb = implements::pixel_value_interpretation_rgb,
        pixel_value_interpretation_rgba = implements::pixel_value_interpretation_rgba,
        pixel_value_interpretation_palette = implements::pixel_value_interpretation_palette,
    };

    reader(FILE* file)
    : file_(file), on_jpeg_sample_col_(0), bits_per_pixel_value_(0),
      pixel_value_interpretation_(pixel_value_interpretation_none) {
    }
    reader()
    : file_(0), on_jpeg_sample_col_(0), bits_per_pixel_value_(0),
      pixel_value_interpretation_(pixel_value_interpretation_none) {
    }
    virtual ~reader() {
    }

    virtual bool read(const char* file) {
        if ((file)) {
            libjpeg::reader reader(this);
            if ((reader.read(file))) {
                return true;
            }
        }
        return false;
    }
    virtual bool read(FILE* file) {
        if ((file)) {
            libjpeg::reader reader(this);
            if ((reader.read(file))) {
                return true;
            }
        }
        return false;
    }
    virtual bool read() {
        return read(file_);
    }

protected:
    virtual bool on_begin_jpeg_image
    (JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        LOG_DEBUG
        ("on_begin_jpeg_image"
         "\n(output_height = " << output_height << ", output_width = " << output_width <<
         ",\n output_components = " << output_components <<
         ", out_color_components = " << out_color_components <<
         ",\n actual_number_of_colors = " << actual_number_of_colors <<
         ", out_color_space = " << out_color_space <<
         " \"" << color_space().name(out_color_space) << "\""
         ",...)...");
        switch(out_color_space) {
        case JCS_GRAYSCALE:
            if (1 != out_color_components) {
                LOG_ERROR("...unexpected 1 != out_color_components");
                success = false;
            } else {
                if (1 != output_components) {
                    LOG_ERROR("...unexpected 1 != output_components");
                    success = false;
                } else {
                    on_jpeg_sample_col_ = &derives::on_greyscale_jpeg_sample_col;
                    pixel_value_interpretation_ = pixel_value_interpretation_greyscale;
                    bits_per_pixel_value_ = (sizeof(JSAMPLE) * 8);
                }
            }
            break;
        case JCS_RGB:
            if (3 != out_color_components) {
                LOG_ERROR("...unexpected 3 != out_color_components");
                success = false;
            } else {
                if ((colormap)) {
                    if (1 != output_components) {
                        LOG_ERROR("...unexpected 1 != output_components");
                        success = false;
                    } else {
                        on_jpeg_sample_col_ = &derives::on_rgb_palette_jpeg_sample_col;
                        pixel_value_interpretation_ = pixel_value_interpretation_palette;
                        bits_per_pixel_value_ = (sizeof(JSAMPLE) * 8);
                    }
                } else {
                    if (3 != output_components) {
                        LOG_ERROR("...unexpected 3 != output_components");
                        success = false;
                    } else {
                        on_jpeg_sample_col_ = &derives::on_rgb_jpeg_sample_col;
                        pixel_value_interpretation_ = pixel_value_interpretation_rgb;
                        bits_per_pixel_value_ = (sizeof(JSAMPLE) * 8);
                    }
                }
            }
            break;
        default:
            LOG_ERROR("...failed color space " << out_color_space << " \"" << color_space().name(out_color_space) << "\" not implemented");
            success = false;
            break;
        }
        if ((success)) {
            success = this->on_begin_image
            (output_width, output_height, 1, output_components,
             bits_per_pixel_value_, pixel_value_interpretation_);
        }
        return success;
    }
    virtual bool on_end_jpeg_image
    (JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        LOG_DEBUG("...on_end_jpeg_image()");
        success = this->on_end_image
        (output_width, output_height, 1, output_components,
         bits_per_pixel_value_, pixel_value_interpretation_);
        pixel_value_interpretation_ = pixel_value_interpretation_none;
        bits_per_pixel_value_ = 0;
        on_jpeg_sample_col_ = 0;
        return success;
    }

    virtual bool on_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = false;
        if ((on_jpeg_sample_col_)) {
            success = (this->*on_jpeg_sample_col_)
            (samples, samples_size, samples_row, samples_col,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_greyscale_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        if (!(1 != samples_size)) {
            byte_t* byte = ((byte_t*)samples);
            rgba_pixel_t pixel(byte[0], byte[0], byte[0]);
            success = this->on_image_pixel
            (pixel, byte, samples_size, samples_col, samples_row, 0,
             output_width, output_height, 1, 1, 8, pixel_value_interpretation_);
        } else {
            success = false;
        }
        return success;
    }
    virtual bool on_rgb_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        if (!(3 != samples_size)) {
            byte_t* byte = ((byte_t*)samples);
            rgba_pixel_t pixel(byte[0], byte[1], byte[2]);
            success = this->on_image_pixel
            (pixel, byte, samples_size, samples_col, samples_row, 0,
             output_width, output_height, 1, 3, 8, pixel_value_interpretation_);
        } else {
            success = false;
        }
        return success;
    }
    virtual bool on_rgb_palette_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        return success;
    }
    
protected:
    FILE* file_;
    bool (derives::*on_jpeg_sample_col_)
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap);
    size_t bits_per_pixel_value_;
    pixel_value_interpretation_t pixel_value_interpretation_;
};

} /// namespace pixel
} /// namespace libjpeg
} /// namespace jpeg
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_PIXEL_READER_HPP 
