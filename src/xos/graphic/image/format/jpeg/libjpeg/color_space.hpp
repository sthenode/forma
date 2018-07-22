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
///   File: color_space.hpp
///
/// Author: $author$
///   Date: 7/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_COLOR_SPACE_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_COLOR_SPACE_HPP

#include "xos/graphic/image/format/jpeg/libjpeg/error.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace jpeg {
namespace libjpeg {

typedef implement_base color_space_implements;
typedef base color_space_extends;
///////////////////////////////////////////////////////////////////////
///  Class: color_space
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS color_space
: virtual public color_space_implements, public color_space_extends {
public:
    typedef color_space_implements implements;
    typedef color_space_extends extends;

    color_space(J_COLOR_SPACE which): which_(which) {
    }
    color_space(const color_space& copy): which_(copy.which_) {
    }
    color_space(): which_(JCS_UNKNOWN) {
    }
    virtual ~color_space() {
    }

    virtual const char* name(J_COLOR_SPACE of) const {
        switch(of) {
        case JCS_GRAYSCALE:
            return "greyscale";
        case JCS_RGB:
            return "rgb";
        case JCS_YCbCr:
            return "ycc";
        case JCS_YCCK:
            return "ycck";
        case JCS_CMYK:
            return "cmyk";
        case JCS_BG_RGB:
            return "bg_rgb";
        case JCS_BG_YCC:
            return "bg_ycc";
        default:
            break;
        }
        return "unknown";
    }

    virtual J_COLOR_SPACE which() const {
        return which_;
    }
    virtual operator J_COLOR_SPACE() const {
        return which_;
    }

protected:
    J_COLOR_SPACE which_;
};

} /// namespace libjpeg
} /// namespace jpeg
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_COLOR_SPACE_HPP 
