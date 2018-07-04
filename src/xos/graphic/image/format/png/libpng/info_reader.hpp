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
///   File: info_reader.hpp
///
/// Author: $author$
///   Date: 7/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_READER_HPP

#include "xos/graphic/image/format/png/libpng/read_struct.hpp"
#include "xos/graphic/image/format/png/libpng/info.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef info_implements info_reader_implements;
typedef info info_reader_extends;
///////////////////////////////////////////////////////////////////////
///  Class: info_readert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = info_reader_implements, class TExtends = info_reader_extends>
class _EXPORT_CLASS info_readert: virtual public TImplements, public TExtends
{
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef extends info_t;
    typedef typename implements::attached_t attached_t;

    info_readert
    (read_struct& _read_struct, attached_t detached = 0, bool is_created = false)
    : extends(_read_struct, detached, is_created),
      read_struct_(_read_struct) {
    }
    virtual ~info_readert() {
    }

    virtual bool create() {
        if ((read_struct_.create())) {
            if ((extends::create())) {
                return true;
            }
            read_struct_.destroy();
        }
        return false;
    }
    virtual bool destroy() {
        bool success = extends::destroy();
        if (!(read_struct_.destroy())) {
            success = false;
        }
        return success;
    }

    virtual ssize_t read(info_t& info) {
        ssize_t count = read_struct_.read(info);
        return count;
    }

protected:
    read_struct& read_struct_;
};
typedef info_readert<> info_reader;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_INFO_READER_HPP 
