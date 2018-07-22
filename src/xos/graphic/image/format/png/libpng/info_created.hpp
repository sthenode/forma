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
///   File: info_created.hpp
///
/// Author: $author$
///   Date: 7/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_CREATED_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_CREATED_HPP

#include "xos/graphic/image/format/png/libpng/struct_created.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef png_infop info_attached_t;
typedef xos::creator info_creator;
typedef xos::attachert<info_attached_t, int, 0, info_creator> info_attacher;
typedef xos::attachedt<info_attached_t, int, 0, info_attacher, base> info_attached;
typedef xos::createdt<info_attached_t, int, 0, info_attacher, info_attached> info_created_extend;
typedef info_attacher info_created_implements;
typedef info_created_extend info_created_extends;
///////////////////////////////////////////////////////////////////////
///  Class: info_createdt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = info_created_implements, class TExtends = info_created_extends>
class _EXPORT_CLASS info_createdt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::attached_t attached_t;
    typedef struct_created struct_created_t;

    info_createdt
    (struct_created_t& struct_created, 
     attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created), struct_created_(struct_created) {
    }
    virtual ~info_createdt() {
    }

    virtual attached_t create_detached() const {
        attached_t detached = 0;
        png_structp struct_detached = 0;

        if ((struct_detached = struct_created_.attached_to())) {

            LOG_DEBUG("png_create_info_struct(struct_detached = " << p_to_string(struct_detached) << ")...");
            if ((detached = png_create_info_struct(struct_detached))) {
                LOG_DEBUG("...png_create_info_struct(struct_detached = " << p_to_string(struct_detached) << ")");
            } else {
                LOG_ERROR("...failed on png_create_info_struct(struct_detached = " << p_to_string(struct_detached) << ")");
            }
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            png_structp struct_detached = 0;

            if ((struct_detached = struct_created_.attached_to())) {

                LOG_DEBUG("png_destroy_info_struct(struct_detached = " << p_to_string(struct_detached) << ", &detached = " << p_to_string(&detached) << ")...");
                png_destroy_info_struct(struct_detached, &detached);
                LOG_DEBUG("...png_destroy_info_struct(struct_detached = " << p_to_string(struct_detached) << ", &detached = " << p_to_string(&detached) << ")");
                return true;
            }
        }
        return false;
    }

protected:
    struct_created_t& struct_created_;
};
typedef info_createdt<> info_created;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_CREATED_HPP 
