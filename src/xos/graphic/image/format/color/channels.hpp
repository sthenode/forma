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
///   File: channels.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_HPP

#include "xos/graphic/image/format/color/channels/rgb.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace color {

typedef int channels_which_t;
enum {
    channels_rgb,
    channels_bgr,

    channels_rgba,
    channels_bgra,

    channels_argb,
    channels_abgr,

    first_channels = channels_rgb,
    last_channels = channels_abgr,
    count_channels = (last_channels - first_channels + 1),

    first_3color_channels = channels_rgb,
    last_3color_channels = channels_bgr,
    count_3color_channels = (last_3color_channels - first_3color_channels + 1)
};
typedef channels_which_t channels_count_t;

///////////////////////////////////////////////////////////////////////
///  Class: channelst
///////////////////////////////////////////////////////////////////////
template
<typename TWhich = channels_which_t, typename TCount = channels_count_t,
 TWhich VFirst = first_channels, TWhich VLast = last_channels, TCount VCount = count_channels, 
 TWhich VFirst3 = first_3color_channels, TWhich VLast3 = last_3color_channels, TCount VCount3 = count_3color_channels,
 class TImplements = implement_base, class TExtends = base>
class _EXPORT_CLASS channelst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TWhich which_t;
    typedef TCount count_t;
    enum {
        first_which = VFirst,
        last_which = VLast,
        count_which = VCount,

        first_which3 = VFirst3,
        last_which3 = VLast3,
        count_which3 = VCount3
    };

    channelst(which_t which): which_(which) {
    }
    channelst(const channelst& copy): which_(copy.which_) {
    }
    virtual ~channelst() {
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

    virtual count_t count() const {
        if ((which_ >= first_which) && (which_ <= last_which)) {
            return count_which;
        } else {
            if ((which_ >= first_which3) && (which_ <= last_which3)) {
                return count_which3;
            } else {
            }
        }
        return 0;
    }

protected:
    which_t which_;
};
typedef channelst<> channels_t;

} /// namespace color
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_COLOR_CHANNELS_HPP 
