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
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_EVENTS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_EVENTS_HPP

#include "xos/graphic/image/format/pixel/rgba.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: reader_eventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS reader_eventst: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef pixel::rgba::value_t rgba_pixel_t;
    typedef pixel::value_t pixel_t;
    typedef pixel::value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = pixel::value_interpretation_none,
        pixel_value_interpretation_greyscale = pixel::value_interpretation_greyscale,
        pixel_value_interpretation_rgb = pixel::value_interpretation_rgb,
        pixel_value_interpretation_rgba = pixel::value_interpretation_rgba,
        pixel_value_interpretation_palette = pixel::value_interpretation_palette,
    };

    virtual bool on_image_pixel
    (pixel_t& pixel, byte_t* pixel_byte, size_t pixel_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_image_pixel
            (pixel, pixel_byte, pixel_bytes,
             image_col, image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }

    virtual bool on_image_col
    (byte_t* col_byte, size_t col_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_image_col
            (col_byte, col_bytes,
             image_col, image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_begin_image_col
    (byte_t* col_byte, size_t col_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_begin_image_col
            (col_byte, col_bytes,
             image_col, image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_end_image_col
    (byte_t* col_byte, size_t col_bytes,
     size_t image_col, size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_end_image_col
            (col_byte, col_bytes,
             image_col, image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }

    virtual bool on_image_row
    (byte_t* row_byte, size_t row_bytes,
     size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_image_row
            (row_byte, row_bytes,
             image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_begin_image_row
    (byte_t* row_byte, size_t row_bytes,
     size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_begin_image_row
            (row_byte, row_bytes,
             image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_end_image_row
    (byte_t* row_byte, size_t row_bytes,
     size_t image_row, size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_end_image_row
            (row_byte, row_bytes,
             image_row, image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }

    virtual bool on_image_plane
    (size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_image_plane
            (image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_begin_image_plane
    (size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_begin_image_plane
            (image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_end_image_plane
    (size_t image_plane,
     size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_end_image_plane
            (image_plane,
             image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }

    virtual bool on_image
    (size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_image
            (image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_begin_image
    (size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_begin_image
            (image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }
    virtual bool on_end_image
    (size_t image_width, size_t image_height, size_t image_planes,
     size_t values_per_pixel, size_t bits_per_value,
     pixel_value_interpretation_t pixel_value_interpretation) {
        bool success = true;
        reader_eventst* to = 0;
        if ((to = reader_events_forward_to())) {
            success = to->on_end_image
            (image_width, image_height, image_planes,
             values_per_pixel, bits_per_value, pixel_value_interpretation);
        }
        return success;
    }

    virtual reader_eventst* forward_reader_events(reader_eventst* to) {
        return 0;
    }
    virtual reader_eventst* reader_events_forward_to() const {
        return 0;
    }
};
typedef reader_eventst<> reader_events;
    
} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_EVENTS_HPP 
