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
///   File: value.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_VALUE_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_VALUE_HPP

#include "xos/graphic/image/format/pixel/color/axes.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {

typedef int value_interpretation_t;
enum {
    value_interpretation_none,
    value_interpretation_palette,
    value_interpretation_greyscale,
    value_interpretation_rgb,
    value_interpretation_bgr,
    value_interpretation_rgba,
    value_interpretation_brga,
    value_interpretation_argb,
    value_interpretation_abgr,

    next_value_interpretation,
    first_value_interpretation = value_interpretation_none,
    last_value_interpretation  = (next_value_interpretation - 1),
    value_interpretations      = (last_value_interpretation - first_value_interpretation + 1)
};

///////////////////////////////////////////////////////////////////////
///  Class: valuet
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS valuet: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual color::axis_t color_axis(color::axes_t which) const {
        return 0;
    }
    virtual color::axis_t color_axis_min() const {
        return 0;
    }
    virtual color::axis_t color_axis_max() const {
        return 0;
    }
    virtual color::axes_t first_color_axis() const {
        return 0;
    }
    virtual color::axes_t last_color_axis() const {
        return 0;
    }
    virtual color::axes_t color_axes() const {
        return 0;
    }
};
typedef valuet<> value_t;

} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_VALUE_HPP 
