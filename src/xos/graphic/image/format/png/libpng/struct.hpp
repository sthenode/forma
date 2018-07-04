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
///   File: struct.hpp
///
/// Author: $author$
///   Date: 7/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_HPP

#include "xos/graphic/image/format/png/libpng/struct_created.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef struct_created_implements struct_implements;
typedef struct_created struct_extends;
///////////////////////////////////////////////////////////////////////
///  Class: structt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = struct_implements, class TExtends = struct_extends>
class _EXPORT_CLASS structt: virtual public TImplements,public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typename implements::attached_t attached_t;

    structt(attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created) {
    }
    virtual ~structt() {
    }
};
typedef structt<> struct_t;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_HPP 
