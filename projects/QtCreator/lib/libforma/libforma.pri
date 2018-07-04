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
#   File: libforma.pri
#
# Author: $author$
#   Date: 7/1/2018
#
# QtCreator .pri file for forma library libforma
########################################################################

########################################################################
# libforma

# libforma TARGET
#
libforma_TARGET = forma
libforma_TEMPLATE = lib
libforma_CONFIG += staticlib

# libforma INCLUDEPATH
#
libforma_INCLUDEPATH += \
$${forma_INCLUDEPATH} \

# libforma DEFINES
#
libforma_DEFINES += \
$${forma_DEFINES} \

########################################################################
# libforma OBJECTIVE_HEADERS
#
#libforma_OBJECTIVE_HEADERS += \
#$${FORMA_SRC}/forma/base/Base.hh \

# libforma OBJECTIVE_SOURCES
#
#libforma_OBJECTIVE_SOURCES += \
#$${FORMA_SRC}/forma/base/Base.mm \

########################################################################
# libforma HEADERS
#
libforma_HEADERS += \
$${FORMA_SRC}/xos/lib/forma/version.hpp \

# libforma SOURCES
#
libforma_SOURCES += \
$${FORMA_SRC}/xos/lib/forma/version.cpp \

########################################################################



