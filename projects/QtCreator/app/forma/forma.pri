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
$${NADIR_SRC}/xos/io/crt/file/reader.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/color/rgba.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/color/axes.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/value.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/rgba.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/reader_events.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/bytes/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/bytes/bgra_reader.hpp \
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
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/reader_events.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/pixel/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/png/libpng/pixel/bgra_reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/jpeg.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/error.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/color_space.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/decompress.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/reader_events.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/pixel/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/pixel/bgra_reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/giflib.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file_reader_events.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file_reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/pixel/reader.hpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/pixel/bgra_reader.hpp \
$${FORMA_SRC}/xos/app/console/forma/main.hpp \

# forma_exe SOURCES
#
forma_exe_SOURCES += \
$${FILA_SRC}/xos/console/main_main.cpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/color/axes.cpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/value.cpp \
$${FORMA_SRC}/xos/graphic/image/format/pixel/rgba.cpp \
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
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/jpeg.cpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/error.cpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/color_space.cpp \
$${FORMA_SRC}/xos/graphic/image/format/jpeg/libjpeg/decompress.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/giflib.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file_reader_events.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/file_reader.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/pixel/reader.cpp \
$${FORMA_SRC}/xos/graphic/image/format/gif/giflib/pixel/bgra_reader.cpp \
$${FORMA_SRC}/xos/app/console/forma/main.cpp \

########################################################################
# forma_exe FRAMEWORKS
#
forma_exe_FRAMEWORKS += \
$${forma_FRAMEWORKS} \

# forma_exe LIBS
#
forma_exe_LIBS += \
$${forma_LIBS} \


