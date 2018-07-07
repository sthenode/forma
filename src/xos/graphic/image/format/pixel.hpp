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
///   File: pixel.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_HPP

#include "xos/graphic/image/format/color/channels.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<typename TColorSample = size_t,
 typename TColorChannels = color::channels_t,
 typename TColorChannelsWhich = color::channels_which_t,
 typename TColorChannelsCount = color::channels_count_t,
 TColorChannelsCount VColorChannelsCount = color::count_channels,
 class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TColorSample color_sample_t;
    typedef TColorChannels color_channels_t;
    typedef TColorChannelsWhich color_channels_which_t;
    typedef TColorChannelsCount color_channels_count_t;
    enum { color_channels_count = VColorChannelsCount };

    pixelt(color_channels_which_t which, color_sample_t max, ...)
    : color_channels_(which) {
        va_list va;
        clear();
        va_start(va, which);
        assign(max, va);
        va_end(va);
    }
    virtual ~pixelt() {
    }

    virtual pixelt& assign(color_sample_t max, va_list va) {
        color_channels_count_t channels = color_channels_.count();
        for (color_channels_count_t c = 0; c < channels; ++c) {
            color_sample_[c] = va_arg(va, color_sample_t);
        }
        color_sample_[color_channels_count] = max;
        color_sample_[color_channels_count + 1] = max;
        return *this;
    }
    virtual pixelt& clear() {
        for (color_channels_count_t c = 0; c < color_channels_count; ++c) {
            color_sample_[c] = 0;
        }
        color_sample_[color_channels_count] = 0;
        color_sample_[color_channels_count + 1] = 0;
        return *this;
    }

    virtual color_sample_t red() const {
        return color_sample_[color::channels::rgb_red]; 
    }
    virtual color_sample_t green() const {
        return color_sample_[color::channels::rgb_green]; 
    }
    virtual color_sample_t blue() const {
        return color_sample_[color::channels::rgb_blue]; 
    }
    virtual color_sample_t alpha() const {
        return color_sample_[color_channels_count]; 
    }
    virtual color_sample_t max() const {
        return color_sample_[color_channels_count + 1]; 
    }

protected:
    color_channels_t color_channels_;
    color_sample_t color_sample_[color_channels_count + 2];
};
typedef pixelt<> pixel_t;

namespace rgb {
///////////////////////////////////////////////////////////////////////
///  Class: pixel_t
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS pixel_t: public format::pixel_t {
public:
    typedef format::pixel_t extends;

    pixel_t
    (color_sample_t red, color_sample_t green,
     color_sample_t blue, color_sample_t max)
    : extends(color::channels_rgb, max, red, green, blue) {
    }
};
} // namespace rgb

namespace rgba {
///////////////////////////////////////////////////////////////////////
///  Class: pixel_t
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS pixel_t: public format::pixel_t {
public:
    typedef format::pixel_t extends;

    pixel_t
    (color_sample_t red, color_sample_t green,
     color_sample_t blue, color_sample_t alpha, color_sample_t max)
    : extends(color::channels_rgba, max, red, green, blue, alpha) {
    }
};
} // namespace rgba

} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_HPP 
