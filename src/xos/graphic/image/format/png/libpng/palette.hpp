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
///   File: palette.hpp
///
/// Author: $author$
///   Date: 7/2/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PALETTE_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PALETTE_HPP

#include "xos/graphic/image/format/png/libpng/color.hpp"
#include "xos/graphic/image/format/png/libpng/struct_created.hpp"
#include "xos/graphic/image/format/png/libpng/info_created.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef color_implements palette_implements;
typedef color palette_extends;
///////////////////////////////////////////////////////////////////////
///  Class: palettet
///////////////////////////////////////////////////////////////////////
template
<class TImplements = palette_implements, class TExtends = palette_extends>
class _EXPORT_CLASS palettet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::attached_t attached_t;

    palettet
    (struct_created& _struct_created, info_created& _info_created,
     attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created),
      struct_created_(_struct_created), info_created_(_info_created),
      colors_(0) {
    }
    virtual ~palettet() {
    }

    virtual size_t get() {
        struct_attached_t struct_detached = 0;

        if ((struct_detached = struct_created_.attached_to())) {
            info_attached_t info_detached = 0;

            if ((info_detached = info_created_.attached_to())) {
                png_int_32 result = 0;
                attached_t detached = 0;
                int colors = 0;

                LOG_DEBUG("png_get_PLTE(struct_detached = " << p_to_string(struct_detached) << ", info_detached = " << p_to_string(info_detached) << ", &detached = " << p_to_string(&detached) << ", &colors = " << p_to_string(&colors) << ")...");
                if ((result = png_get_PLTE(struct_detached, info_detached, &detached, &colors))) {
                    LOG_DEBUG("...png_get_PLTE(struct_detached = " << p_to_string(struct_detached) << ", info_detached = " << p_to_string(info_detached) << ", &detached = " << p_to_string(&detached) << ", &colors = " << p_to_string(&colors) << ")");
                    this->attach(detached);
                    return this->set_colors(colors);
                } else {
                    LOG_ERROR("...failed result = " << result << " on png_get_PLTE(struct_detached = " << p_to_string(struct_detached) << ", info_detached = " << p_to_string(info_detached) << ", &detached = " << p_to_string(&detached) << ", &colors = " << p_to_string(&colors) << ")");
                }
            } else {
                LOG_ERROR("...unexpected info_detached = 0 on get()");
            }
        } else {
            LOG_ERROR("...unexpected struct_detached = 0 on get()");
        }
        return 0;
    }
    virtual size_t put() {
        return 0;
    }

    virtual size_t set_colors(size_t to) {
        colors_ = to;
        return colors_;
    }
    virtual size_t colors() const {
        return colors_;
    }

    virtual attached_t operator[](size_t color) const {
        attached_t detached = 0;
        if ((detached = this->attached_to()) && (color < colors())) {
            return &detached[color];
        }
        return 0;
    }
    virtual operator attached_t() const {
        return this->attached_to();
    }

protected:
    struct_created& struct_created_;
    info_created& info_created_;
    size_t colors_;
};
typedef palettet<> palette;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_PALETTE_HPP 
