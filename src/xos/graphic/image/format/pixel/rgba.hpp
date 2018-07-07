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
///   File: rgba.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_RGBA_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_RGBA_HPP

#include "xos/graphic/image/format/pixel/value.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {
namespace rgba {

///////////////////////////////////////////////////////////////////////
///  Class: valuet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pixel::value_t, class TExtends = base>
class _EXPORT_CLASS valuet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    valuet
    (color::axis_t red, color::axis_t green, color::axis_t blue,
     color::axis_t alpha = 255, color::axis_t max = 255)
    : red_(red), green_(green), blue_(blue), alpha_(alpha), max_(max) {
    }
    valuet(const valuet& copy)
    : red_(copy.red_), green_(copy.green_), blue_(copy.blue_),
      alpha_(copy.alpha_), max_(copy.max_) {
    }
    virtual ~valuet() {
    }

    virtual color::axis_t color_axis(color::axes_t which) const {
        switch (which) {
        case color::rgba::axis_red:
            return red_;
        case color::rgba::axis_green:
            return green_;
        case color::rgba::axis_blue:
            return blue_;
        case color::rgba::axis_alpha:
            return alpha_;
        }
        return 0;
    }
    virtual color::axis_t color_axis_min() const {
        return 0;
    }
    virtual color::axis_t color_axis_max() const {
        return max_;
    }
    virtual color::axes_t first_color_axis() const {
        return color::rgba::axis_red;
    }
    virtual color::axes_t last_color_axis() const {
        return  color::rgba::axis_alpha;
    }
    virtual color::axes_t color_axes() const {
        return color::axes_rgba;
    }

    virtual valuet& operator()
    (color::axis_t red, color::axis_t green, color::axis_t blue,
     color::axis_t alpha = 255, color::axis_t max = 255) {
        red_ = red; green_ = green; blue_ = blue; alpha_ = alpha; max_ = max;
        return *this;
    }

protected:
    color::axis_t red_, green_, blue_, alpha_, max_;
};
typedef valuet<> value_t;

} /// namespace rgba
} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_RGBA_HPP 
