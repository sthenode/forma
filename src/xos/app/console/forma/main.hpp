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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/4/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_FORMA_MAIN_HPP
#define _XOS_APP_CONSOLE_FORMA_MAIN_HPP

#include "xos/console/getopt/main.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/graphic/image/format/png/libpng/reader.hpp"
#include "xos/graphic/image/format/png/libpng/pixel/reader.hpp"
#include "xos/graphic/image/format/png/libpng/pixel/bgra_reader.hpp"

namespace xos {
namespace app {
namespace console {
namespace forma {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = xos::console::getopt::main::implements, 
 class TExtends = xos::console::getopt::main>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::char_t char_t;

    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }
    
protected:
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t count = 0;
        const char_t* arg = 0;
        io::crt::file::byte_reader in(this->std_in());
        graphic::image::format::png::libpng::pixel::bgra_reader png(in);

        if ((optind < argc) && (argv) && (arg = argv[optind]) && (arg[0])) {
            if (!(in.open(arg))) {
            }
        }
        if ((in.attached_to())) {
            if (0 < (count = png.read())) {
            }
        }
        if (!(in.closed())) {
        }
        return err;
    }
};
typedef maint<> main;

} /// namespace forma
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_FORMA_MAIN_HPP 
