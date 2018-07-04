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
///   File: struct_created.hpp
///
/// Author: $author$
///   Date: 7/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_CREATED_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_CREATED_HPP

#include "xos/graphic/image/format/png/libpng/png.hpp"
#include "xos/base/created.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef png_structp struct_attached_t;
typedef xos::creator struct_creator;
typedef xos::attachert<struct_attached_t, int, 0, struct_creator> struct_attacher;
typedef xos::attachedt<struct_attached_t, int, 0, struct_attacher, base> struct_attached;
typedef xos::createdt<struct_attached_t, int, 0, struct_attacher, struct_attached> struct_created_extend;
typedef struct_attacher struct_created_implements;
typedef struct_created_extend struct_created_extends;
///////////////////////////////////////////////////////////////////////
///  Class: struct_createdt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = struct_created_implements, class TExtends = struct_created_extends>
class _EXPORT_CLASS struct_createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typename implements::attached_t attached_t;

    struct_createdt(attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created), bytesRead_(0), bytesWritten_(0) {
    }
    virtual ~struct_createdt() {
    }

    virtual attached_t create_detached() const {
        attached_t detached = 0;
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        return false;
    }

    virtual void on_Error(png_structp structp, png_const_charp charp) {
    }
    virtual void on_Warn(png_structp structp, png_const_charp charp) {
    }
    static void ErrorFn(png_structp structp, png_const_charp charp) {
        png_voidp error_ptr = 0;
        struct_createdt* pngStruct = 0;
        if ((pngStruct = (struct_createdt*)(error_ptr = png_get_error_ptr(structp))))
            pngStruct->on_Error(structp, charp);
        throw error_string(charp);
    }
    static void WarnFn(png_structp structp, png_const_charp charp) {
        png_voidp error_ptr = 0;
        struct_createdt* pngStruct = 0;
        if ((pngStruct = (struct_createdt*)(error_ptr = png_get_error_ptr(structp))))
            pngStruct->on_Warn(structp, charp);
    }

    virtual png_uint_32 SetBytesRead(png_uint_32 to) {
        png_uint_32 prevBytesRead = bytesRead_;
        bytesRead_ = to;
        return prevBytesRead;
    }
    virtual png_uint_32 bytesRead() const {
        return bytesRead_;
    }
    virtual png_uint_32 SetBytesWritten(png_uint_32 to) {
        png_uint_32 prevBytesWritten = bytesWritten_;
        bytesWritten_ = to;
        return prevBytesWritten;
    }
    virtual png_uint_32 bytesWritten() const {
        return bytesWritten_;
    }

protected:
    png_uint_32 bytesRead_, bytesWritten_;
};
typedef struct_createdt<> struct_created;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_STRUCT_CREATED_HPP 
