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
///   File: rgb.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_RGB_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_RGB_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace color {
namespace channels {

typedef int rgb_which_t;
enum {
    rgb_red,
    rgb_green,
    rgb_blue,

    first_rgb = rgb_red,
    last_rgb = rgb_blue,
    count_rgb = (last_rgb - first_rgb + 1)
};

typedef int bgr_which_t;
enum {
    bgr_blue,
    bgr_green,
    bgr_red,

    first_bgr = bgr_blue,
    last_bgr = bgr_red,
    count_bgr = (last_bgr - first_bgr + 1)
};

typedef int rgba_which_t;
enum {
    rgba_red,
    rgba_green,
    rgba_blue,
    rgba_alpha,

    first_rgba = rgba_red,
    last_rgba = rgba_alpha,
    count_rgba = (last_rgba - first_rgba + 1)
};

typedef int bgra_which_t;
enum {
    bgra_blue,
    bgra_green,
    bgra_red,
    bgra_alpha,

    first_bgra = bgra_blue,
    last_bgra = bgra_alpha,
    count_bgra = (last_bgra - first_bgra + 1)
};

typedef int argb_which_t;
enum {
    argb_alpha,
    argb_red,
    argb_green,
    argb_blue,

    first_argb = argb_alpha,
    last_argb = argb_blue,
    count_argb = (last_argb - first_argb + 1)
};

typedef int abgr_which_t;
enum {
    abgr_blue,
    abgr_green,
    abgr_red,
    abgr_alpha,

    first_abgr = abgr_blue,
    last_abgr = abgr_alpha,
    count_abgr = (last_abgr - first_abgr + 1)
};

///////////////////////////////////////////////////////////////////////
///  Class: rgbat
///////////////////////////////////////////////////////////////////////
template
<typename TWhich, 
 TWhich VRed, TWhich VGreen, TWhich VBlue, TWhich VAlpha, TWhich VCount,
 class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS rgbat: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TWhich which_t;
    typedef TWhich count_t;
    enum { 
        which_red = VRed, 
        which_green = VGreen,
        which_blue = VBlue,
        which_alpha = VAlpha,
        count_which = VCount 
    };

    rgbat(which_t which): which_(which) {
    }
    rgbat(const rgbat& copy): which_(copy.which_) {
    }
    virtual ~rgbat() {
    }

    virtual which_t set_which(which_t to) {
        return which_;
    }
    virtual which_t which() const {
        return which_;
    }
    virtual operator which_t() const {
        return which_;
    }

    virtual which_t red() const {
        return which_red;
    }
    virtual which_t green() const {
        return which_green;
    }
    virtual which_t blue() const {
        return which_blue;
    }
    virtual which_t alpha() const {
        return which_alpha;
    }

    virtual count_t count() const {
        return count_which;
    }

    virtual bool has_alpha() const {
        return which_alpha < count_which;
    }

protected:
    which_t which_;
};

typedef rgbat<rgb_which_t, rgb_red, rgb_green, rgb_blue, count_rgb, count_rgb> rgb_t;
typedef rgbat<bgr_which_t, bgr_red, bgr_green, bgr_blue, count_rgb, count_bgr> bgr_t;

typedef rgbat<rgba_which_t, rgba_red, rgba_green, rgba_blue, rgba_alpha, count_rgba> rgba_t;
typedef rgbat<bgra_which_t, bgra_red, bgra_green, bgra_blue, bgra_alpha, count_bgra> bgra_t;

typedef rgbat<argb_which_t, argb_red, argb_green, argb_blue, argb_alpha, count_argb> argb_t;
typedef rgbat<abgr_which_t, abgr_red, abgr_green, abgr_blue, abgr_alpha, count_abgr> abgr_t;

} /// namespace channels
} /// namespace color
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_RGB_HPP 
