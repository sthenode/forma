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
# build QtCreator .pri file for forma
########################################################################
HOME_UNAME = $$system(uname)

contains(HOME_UNAME,Darwin) {
HOME = /Users/jboyd
} else {
HOME = /home/jboyd
}

########################################################################
# giflib
#
# pkg-config --cflags --libs giflib
#

# build giflib INCLUDEPATH
#
build_giflib_INCLUDEPATH += \
$${HOME}/build/giflib/include \

# build giflib DEFINES
#
build_giflib_DEFINES += \

# build giflib LIBS
#
build_giflib_LIBS += \
-L$${HOME}/build/giflib/lib \
-lgif \

########################################################################
# libjpeg
#
# pkg-config --cflags --libs libjpeg
#

# build libjpeg INCLUDEPATH
#
build_libjpeg_INCLUDEPATH += \
$${HOME}/build/jpeg/include \

# build libjpeg DEFINES
#
build_libjpeg_DEFINES += \

# build libjpeg LIBS
#
build_libjpeg_LIBS += \
-L$${HOME}/build/jpeg/lib \
-ljpeg \

########################################################################
# libpng
#
# pkg-config --cflags --libs libpng
#

# build libpng INCLUDEPATH
#
build_libpng_INCLUDEPATH += \
$${HOME}/build/libpng/include \

# build libpng DEFINES
#
build_libpng_DEFINES += \

# build libpng LIBS
#
build_libpng_LIBS += \
-L${HOME}/build/libpng/lib \
-lpng \

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

# build crono INCLUDEPATH
#
build_crono_INCLUDEPATH += \

# build crono DEFINES
#
build_crono_DEFINES += \

# build crono LIBS
#
build_crono_LIBS += \

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

# build fila INCLUDEPATH
#
build_fila_INCLUDEPATH += \

# build fila DEFINES
#
build_fila_DEFINES += \

# build fila LIBS
#
build_fila_LIBS += \

########################################################################
# forma

# build forma INCLUDEPATH
#
build_forma_INCLUDEPATH += \
$${build_fila_INCLUDEPATH} \
$${build_crono_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \
$${build_libpng_INCLUDEPATH} \
$${build_libjpeg_INCLUDEPATH} \
$${build_giflib_INCLUDEPATH} \


# build forma DEFINES
#
build_forma_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_crono_DEFINES} \
$${build_fila_DEFINES} \
$${build_libpng_DEFINES} \
$${build_libjpeg_DEFINES} \
$${build_giflib_DEFINES} \


# build forma LIBS
#
build_forma_LIBS += \
$${build_fila_LIBS} \
$${build_crono_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \
$${build_libpng_LIBS} \
$${build_libjpeg_LIBS} \
$${build_giflib_LIBS} \