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
///   File: error.hpp
///
/// Author: $author$
///   Date: 7/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_ERROR_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_ERROR_HPP

#include "xos/graphic/image/format/jpeg/libjpeg/jpeg.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace jpeg {
namespace libjpeg {

enum error_which_t {
    error_none,
    error_failed,

    next_error,
    first_error = error_none,
    last_error = next_error - 1,
    errors = last_error - first_error + 1
};

typedef implement_base error_implements;
typedef base error_extends;
///////////////////////////////////////////////////////////////////////
///  Class: error
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS error: virtual public error_implements, public error_extends {
public:
    typedef error_implements implements;
    typedef error_extends extends;

    error(error_which_t which = error_none): which_(which) {
    }
    error(const error& copy): which_(copy.which_) {
    }
    virtual ~error() {
    }

    virtual error_which_t which() const {
        return which_;
    }
    virtual operator error_which_t() const {
        return which_;
    }

protected:
    error_which_t which_;
};

} /// namespace libjpeg
} /// namespace jpeg
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_ERROR_HPP 
