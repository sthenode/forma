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
///   File: read_struct.hpp
///
/// Author: $author$
///   Date: 7/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READ_STRUCT_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READ_STRUCT_HPP

#include "xos/graphic/image/format/png/libpng/struct_created.hpp"
#include "xos/graphic/image/format/png/libpng/info.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace png {
namespace libpng {

typedef struct_created_implements read_struct_implements;
typedef struct_created read_struct_extends;
///////////////////////////////////////////////////////////////////////
///  Class: read_structt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = read_struct_implements, class TExtends = read_struct_extends>
class _EXPORT_CLASS read_structt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef info info_t;
    typedef read_structt read_struct_t;
    typedef typename implements::attached_t attached_t;
    typedef xos::io::crt::file::byte_reader byte_file_t;
    typedef xos::io::byte_reader byte_reader_t;

    read_structt
    (byte_reader_t& in, attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created), in_(in) {
    }
    read_structt
    (FILE* file, attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created), file_(file), in_(file_) {
    }
    read_structt(attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created), in_(file_) {
    }
    virtual ~read_structt() {
    }

    virtual attached_t create_detached() const {
        png_const_charp user_png_ver = PNG_LIBPNG_VER_STRING;
        png_voidp error_ptr = ((png_voidp)this);
        png_error_ptr error_fn = this->ErrorFn;
        png_error_ptr warn_fn = this->WarnFn;
        attached_t detached = 0;

        LOG_DEBUG("png_create_read_struct(user_png_ver = \"" << user_png_ver << "\")...");
        if (((detached = png_create_read_struct
            (user_png_ver, error_ptr, error_fn, warn_fn)))) {
            png_voidp io_ptr = ((png_voidp)this);
            png_rw_ptr read_data_fn  = this->ReadFn;

            LOG_DEBUG("...png_create_read_struct(user_png_ver = \"" << user_png_ver << "\")");
            LOG_DEBUG("png_set_read_fn()...");
            png_set_read_fn(detached, io_ptr, read_data_fn);
            LOG_DEBUG("...png_set_read_fn()");
        } else {
            LOG_ERROR("...failed on png_create_read_struct(user_png_ver = \"" << user_png_ver << "\")");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((detached)) {
            LOG_DEBUG("png_destroy_read_struct()...");
            png_destroy_read_struct(&detached, NULL, NULL);
            LOG_DEBUG("...png_destroy_read_struct()");
            return true;
        }
        return false;
    }

    virtual bool begin_read(const char* file) {
        if ((file) && (file_.open(file))) {
            return true;
        }
        return false;
    }
    virtual bool end_read(const char* file) {
        if ((file) && (file_.close())) {
            return true;
        }
        return false;
    }
    virtual bool begin_read(FILE* file) {
        if ((file) && (file_.attach(file))) {
            return true;
        }
        return false;
    }
    virtual bool end_read(FILE* file) {
        if ((file) && (file_.detach())) {
            return true;
        }
        return false;
    }
    virtual ssize_t read(info_t& info) {
        ssize_t count = info.Read();
        return count;
    }

    virtual void on_ReadFn
    (attached_t structp, png_bytep bytep, png_size_t size) {
        ssize_t length = 0;

        if (0 > (length = in_.read(bytep, size))) {
            LOG_ERROR("...failed length = " << length << " on in_.read(bytep = " << p_to_string(bytep) << ", size = " << size << ")");
            this->bytesRead_ = 0;
        } else {
            this->bytesRead_ += length;
        }
    }
    static void ReadFn
    (attached_t structp, png_bytep bytep, png_size_t size) {
        read_struct_t* read_struct = 0;
        png_voidp io_ptr = 0;

        if ((read_struct = (read_struct_t*)(io_ptr = png_get_io_ptr(structp)))) {
            read_struct->on_ReadFn(structp, bytep, size);
        } else {
            LOG_ERROR("...unexpected 0 == png_get_io_ptr(structp = " << p_to_string(structp) << ")");
        }
    }

protected:
    byte_file_t file_;
    byte_reader_t& in_;
};
typedef read_structt<> read_struct;

} /// namespace libpng
} /// namespace png
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PNG_LIBPNG_READ_STRUCT_HPP 
