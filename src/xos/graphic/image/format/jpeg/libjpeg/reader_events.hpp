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
///   Date: 7/21/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_READER_EVENTS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_READER_EVENTS_HPP

#include "xos/graphic/image/format/jpeg/libjpeg/jpeg.hpp"
#include "xos/graphic/image/format/pixel.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace jpeg {
namespace libjpeg {

typedef implement_base reader_events_implements;
///////////////////////////////////////////////////////////////////////
///  Class: reader_events
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS reader_events: virtual public reader_events_implements {
public:
    typedef reader_events_implements implements;
    typedef format::pixel_t pixel_t;

    virtual bool on_jpeg_image
    (JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_jpeg_image
            (output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_begin_jpeg_image
    (JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_begin_jpeg_image
            (output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_end_jpeg_image
    (JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_end_jpeg_image
            (output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }

    virtual bool on_jpeg_sample_row
    (JSAMPROW samples, size_t samples_size, size_t samples_row,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_jpeg_sample_row
            (samples, samples_size, samples_row,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_begin_jpeg_sample_row
    (JSAMPROW samples, size_t samples_size, size_t samples_row,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_begin_jpeg_sample_row
            (samples, samples_size, samples_row,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_end_jpeg_sample_row
    (JSAMPROW samples, size_t samples_size, size_t samples_row,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_end_jpeg_sample_row
            (samples, samples_size, samples_row,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }

    virtual bool on_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_jpeg_sample_col
            (samples, samples_size, samples_row, samples_col,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_begin_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_begin_jpeg_sample_col
            (samples, samples_size, samples_row, samples_col,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }
    virtual bool on_end_jpeg_sample_col
    (JSAMPROW samples, size_t samples_size,
     size_t samples_row, size_t samples_col,
     JDIMENSION output_height, JDIMENSION output_width,
     JDIMENSION output_components, JDIMENSION out_color_components,
     JDIMENSION actual_number_of_colors, J_COLOR_SPACE out_color_space,
     JSAMPARRAY colormap) {
        bool success = true;
        reader_events* events = 0;
        if ((events = jpeg_reader_events_forward_to())) {
            success = events->on_end_jpeg_sample_col
            (samples, samples_size, samples_row, samples_col,
             output_height, output_width, output_components,
             out_color_components, actual_number_of_colors,
             out_color_space, colormap);
        }
        return success;
    }

    virtual reader_events* forward_jpeg_reader_events(reader_events* to) {
        return 0;
    }
    virtual reader_events* jpeg_reader_events_forward_to() const {
        return 0;
    }
};

} /// namespace libjpeg
} /// namespace jpeg
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_READER_EVENTS_HPP 
