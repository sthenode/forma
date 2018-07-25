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
///   File: bgra_reader.hpp
///
/// Author: $author$
///   Date: 7/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_BGRA_READER_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_BGRA_READER_HPP

#include "xos/graphic/image/format/gif/giflib/pixel/reader.hpp"
#include "xos/graphic/image/format/pixel/bytes/bgra_reader.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace gif {
namespace giflib {
namespace pixel {

typedef format::pixel::bytes::bgra_readert
<pixel::reader_implements, pixel::reader> bgra_reader;

} /// namespace pixel
} /// namespace giflib
} /// namespace gif
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_PIXEL_BGRA_READER_HPP 
