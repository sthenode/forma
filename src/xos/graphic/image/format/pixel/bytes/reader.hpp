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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_READER_HPP

#include "xos/graphic/image/format/pixel/reader.hpp"
#include "xos/base/to_string.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {
namespace bytes {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>
class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual byte_t* detach_image
    (size_t& width, size_t& height, size_t& depth, size_t& size) {
        return 0;
    }

    virtual byte_t* alloc_image
    (size_t width, size_t height, size_t depth, size_t size) {
        return 0;
    }
    virtual void free_image() {
    }
};
typedef readert<> reader;

///////////////////////////////////////////////////////////////////////
///  Class: reader_extendt
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>

class _EXPORT_CLASS reader_extendt
: virtual public reader,
  virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    reader_extendt(io::byte_reader& in)
    : extends(in), image_width_(0), image_height_(0),
      image_depth_(0), image_size_(0), bytes_(0) {
    }
    reader_extendt(FILE* in)
    : extends(in), image_width_(0), image_height_(0),
      image_depth_(0), image_size_(0), bytes_(0) {
    }
    reader_extendt()
    : image_width_(0), image_height_(0),
      image_depth_(0), image_size_(0), bytes_(0) {
    }
    virtual ~reader_extendt() {
        free_image();
    }

    virtual byte_t* detach_image
    (size_t& width, size_t& height, size_t& depth, size_t& size) {
        byte_t* bytes = bytes_;
        size = image_size_;
        width = image_width_;
        height = image_height_;
        depth = image_depth_;
        bytes_ = 0;
        image_width_ = (image_height_ = (image_depth_ = (image_size_ = 0)));
        return bytes;
    }

    virtual byte_t* alloc_image
    (size_t width, size_t height, size_t depth, size_t size) {
        LOG_DEBUG("new byte_t[size = " << size << "]...");
        if ((bytes_ = new byte_t[size])) {
            LOG_DEBUG("..." << pointer_to_string(bytes_) << " = new byte_t[size = " << size << "]");
            image_width_ = width;
            image_height_ = height;
            image_depth_ = depth;
            image_size_ = size;
            LOG_DEBUG("::memset(bytes_ = " << pointer_to_string(bytes_) << ", " << ((byte_t)-1) << ", size = " << size << ")...");
            ::memset(bytes_, ((byte_t)-1), size);
            LOG_DEBUG("...::memset(bytes_ = " << pointer_to_string(bytes_) << ", " << ((byte_t)-1) << ", size = " << size << ")");
            return bytes_;
        }
        return 0;
    }
    virtual void free_image() {
        image_width_ = (image_height_ = (image_depth_ = (image_size_ = 0)));
        if ((bytes_)) {
            LOG_DEBUG("delete[] " << pointer_to_string(bytes_) << "...");
            delete[] bytes_;
            LOG_DEBUG("...delete[] " << pointer_to_string(bytes_));
            bytes_ = 0;
        }
    }

protected:
    size_t image_width_, image_height_, image_depth_, image_size_;
    byte_t* bytes_;
};

} /// namespace bytes
} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_BYTES_READER_HPP 
