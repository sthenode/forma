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
///   File: bgra_reader.hpp
///
/// Author: $author$
///   Date: 7/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_BGRA_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_BGRA_READER_HPP

#include "xos/graphic/image/format/pixel/bytes/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {
namespace bytes {

///////////////////////////////////////////////////////////////////////
///  Class: bgra_readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements, class TReaderExtends,
 class TExtends = reader_extendt<TImplements, TReaderExtends> >

class _EXPORT_CLASS bgra_readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef bgra_readert derives;

    typedef pixel::value_t pixel_t;
    typedef pixel::value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = pixel::value_interpretation_none,
        pixel_value_interpretation_greyscale = pixel::value_interpretation_greyscale,
        pixel_value_interpretation_rgb = pixel::value_interpretation_rgb,
        pixel_value_interpretation_rgba = pixel::value_interpretation_rgba,
        pixel_value_interpretation_palette = pixel::value_interpretation_palette,
    };

    bgra_readert(io::byte_reader& in): extends(in), on_image_pixel_(0) {
    } 
    bgra_readert(FILE* in): extends(in), on_image_pixel_(0) {
    } 
    bgra_readert(): on_image_pixel_(0) {
    } 
    virtual ~bgra_readert() {
        this->free_image();
    }

    virtual bool on_begin_image
    (size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        size_t image_bit_depth = 0, image_byte_depth = 0, image_size = 0;

        switch (pixel_value_interpretation) {

        case pixel_value_interpretation_none: {
            if ((1 == image_planes) && (0 == values_per_pixel)
                && ((24 == bits_per_value))) {
                image_byte_depth = 4;
                image_bit_depth = image_byte_depth*8;
                image_size = (image_height * image_width * image_byte_depth);
                on_image_pixel_ = &derives::on_rgb_image_pixel;
            } else {
                LOG_ERROR("invalid image configuration values_per_pixel = " << values_per_pixel << ", bits_per_value = " << bits_per_value << "");
                return false;
            }
            break; }

        case pixel_value_interpretation_greyscale: {
            if ((1 == image_planes) && (8 == bits_per_value)
                && ((1 == values_per_pixel))) {
                image_byte_depth = 4;
                image_bit_depth = image_byte_depth*8;
                image_size = (image_height * image_width * image_byte_depth);
                on_image_pixel_ = &derives::on_greyscale_image_pixel;
            } else {
                LOG_ERROR("invalid image configuration values_per_pixel = " << values_per_pixel << ", bits_per_value = " << bits_per_value << "");
                return false;
            }
            break; }

        case pixel_value_interpretation_rgb: {
            if ((1 == image_planes) && (8 == bits_per_value)
                && ((3 == values_per_pixel))) {
                image_byte_depth = 4;
                image_bit_depth = image_byte_depth*8;
                image_size = (image_height * image_width * image_byte_depth);
                on_image_pixel_ = &derives::on_rgb_image_pixel;
            } else {
                LOG_ERROR("invalid image configuration values_per_pixel = " << values_per_pixel << ", bits_per_value = " << bits_per_value << "");
                return false;
            }
            break; }

        case pixel_value_interpretation_rgba: {
            if ((1 == image_planes) && (8 == bits_per_value)
                && ((4 == values_per_pixel))) {
                image_byte_depth = 4;
                image_bit_depth = image_byte_depth*8;
                image_size = (image_height * image_width * image_byte_depth);
                on_image_pixel_ = &derives::on_rgba_image_pixel;
            } else {
                LOG_ERROR("invalid image configuration values_per_pixel = " << values_per_pixel << ", bits_per_value = " << bits_per_value << "");
                return false;
            }
            break; }

        case pixel_value_interpretation_palette: {
            if ((1 == image_planes) && (8 == bits_per_value)
                && (3 <= values_per_pixel) && (4 >= values_per_pixel)) {
                image_byte_depth = 4;
                image_bit_depth = image_byte_depth*8;
                image_size = (image_height * image_width * image_byte_depth);
                if (3 < values_per_pixel) {
                    on_image_pixel_ = &derives::on_rgba_image_pixel;
                } else {
                    on_image_pixel_ = &derives::on_rgb_image_pixel;
                }
            } else {
                LOG_ERROR("invalid image configuration values_per_pixel = " << values_per_pixel << ", bits_per_value = " << bits_per_value << "");
                return false;
            }
            break; }

        default:
            LOG_ERROR("imvalid pixel_value_interpretation = " << pixel_value_interpretation << "");
            return false;
        }
        this->free_image();
        if ((this->alloc_image
             (image_width, image_height, image_bit_depth, image_size))) {
            return true;
        }
        return false;
    }
    virtual bool on_end_image
    (size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        on_image_pixel_ = 0;
        return success;
    }

    virtual bool on_image_pixel
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = false;
        if ((on_image_pixel_)) {
            success = (this->*on_image_pixel_)
            (pixel, pixel_byte, pixel_bytes, image_col, image_row, image_plane,
             image_width, image_height, image_planes, values_per_pixel,
             bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_greyscale_image_pixel
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        if ((pixel_byte) && (1 == pixel_bytes)) {
            size_t pixel_offset = ((image_row*image_width)+(image_col))*4;
            if ((this->bytes_) && (this->image_size_ > pixel_offset)) {
                byte_t* byte = this->bytes_ + pixel_offset;
                byte[0] = *pixel_byte;
                byte[1] = *pixel_byte;
                byte[2] = *pixel_byte;
                byte[3] = 255;
            }
        } else {
            success = false;
        }
        return success;
    }
    virtual bool on_rgb_image_pixel
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        size_t pixel_offset = ((image_row*image_width)+(image_col))*4;
        if ((this->bytes_) && (this->image_size_ > pixel_offset)) {
            byte_t* byte = this->bytes_ + pixel_offset;
            byte[0] = pixel.color_axis(color::rgba::axis_blue);
            byte[1] = pixel.color_axis(color::rgba::axis_green);
            byte[2] = pixel.color_axis(color::rgba::axis_red);
            byte[3] = 255;
            LOG_TRACE("col = " << image_col << " row = " << image_row << " byte[" << pixel_offset << "] = (" << byte[0] << ", "  << byte[1] << ", "  << byte[2] << ", "  << byte[3] << ")");
        }
        return success;
    }
    virtual bool on_rgba_image_pixel
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        size_t pixel_offset = ((image_row*image_width)+(image_col))*4;
        if ((this->bytes_) && (this->image_size_ > pixel_offset)) {
            byte_t* byte = this->bytes_ + pixel_offset;
            byte[0] = pixel.color_axis(color::rgba::axis_blue);
            byte[1] = pixel.color_axis(color::rgba::axis_green);
            byte[2] = pixel.color_axis(color::rgba::axis_red);
            byte[3] = pixel.color_axis(color::rgba::axis_alpha);
            LOG_TRACE("col = " << image_col << " row = " << image_row << " byte[" << pixel_offset << "] = (" << byte[0] << ", "  << byte[1] << ", "  << byte[2] << ", "  << byte[3] << ")");
        }
        return success;
    }

protected:
    bool (derives::*on_image_pixel_)
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation);
};

} /// namespace bytes
} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_BGRA_READER_HPP 
