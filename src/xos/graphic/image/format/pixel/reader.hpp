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
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_HPP

#include "xos/graphic/image/format/pixel/reader_events.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template <class TImplements = reader_events>
class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::pixel_value_interpretation_t pixel_value_interpretation_t;
    enum {
        pixel_value_interpretation_none = implements::pixel_value_interpretation_none,
        pixel_value_interpretation_greyscale = implements::pixel_value_interpretation_greyscale,
        pixel_value_interpretation_rgb = implements::pixel_value_interpretation_rgb,
        pixel_value_interpretation_rgba = implements::pixel_value_interpretation_rgba,
        pixel_value_interpretation_palette = implements::pixel_value_interpretation_palette,
    };

    virtual bool read() {
        return false;
    }
};
typedef readert<> reader;

} /// namespace pixel
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_PIXEL_READER_HPP 
