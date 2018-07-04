########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: forma.pri
#
# Author: $author$
#   Date: 7/1/2018
#
# QtCreator .pri file for forma executable forma
########################################################################

########################################################################
# forma

# forma_exe TARGET
#
forma_exe_TARGET = forma

# forma_exe INCLUDEPATH
#
forma_exe_INCLUDEPATH += \
$${forma_INCLUDEPATH} \

# forma_exe DEFINES
#
forma_exe_DEFINES += \
$${forma_DEFINES} \

########################################################################
# forma_exe OBJECTIVE_HEADERS
#
#forma_exe_OBJECTIVE_HEADERS += \
#$${FORMA_SRC}/forma/base/Base.hh \

# forma_exe OBJECTIVE_SOURCES
#
#forma_exe_OBJECTIVE_SOURCES += \
#$${FORMA_SRC}/forma/base/Base.mm \

########################################################################
# forma_exe HEADERS
#
forma_exe_HEADERS += \
$${FORMA_SRC}/xos/graphic/image/format/color/channels/rgb.hpp \
$${FORMA_SRC}/xos/graphic/image/format/color/channels.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/png.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/color.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/palette.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/struct_created.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/struct.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info_created.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/read_struct.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info_reader.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \

# forma_exe SOURCES
#
forma_exe_SOURCES += \
$${FORMA_SRC}/xos/graphic/image/format/color/channels/rgb.cpp \
$${FORMA_SRC}/xos/graphic/image/format/color/channels.cpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/png.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/color.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/palette.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/struct_created.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/struct.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info_created.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/read_struct.cpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/info_reader.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \

########################################################################
# forma_exe FRAMEWORKS
#
forma_exe_FRAMEWORKS += \
$${forma_FRAMEWORKS} \

# forma_exe LIBS
#
forma_exe_LIBS += \
$${forma_LIBS} \

