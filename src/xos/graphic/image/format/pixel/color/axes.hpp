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
///   File: axes.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_COLOR_AXES_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_COLOR_AXES_HPP

#include "xos/graphic/image/format/pixel/color/rgba.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {
namespace color {

typedef uint64_t axis_t;
typedef int axes_t;
enum {
    axes_unknown,
    axes_rgba,
    
    next_axes,
    first_axes = axes_rgba,
    last_axes  = (next_axes - 1),
    axes       = (last_axes - first_axes + 1)
};

} /// namespace color
} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_COLOR_AXES_HPP 
