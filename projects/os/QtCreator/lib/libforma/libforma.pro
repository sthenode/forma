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
#   File: libforma.pro
#
# Author: $author$
#   Date: 7/1/2018
#
# QtCreator .pro file for forma library libforma
########################################################################
include(../../../../../build/QtCreator/forma.pri)
include(../../../../QtCreator/forma.pri)
include(../../forma.pri)
include(../../../../QtCreator/lib/libforma/libforma.pri)

TARGET = $${libforma_TARGET}
TEMPLATE = $${libforma_TEMPLATE}
CONFIG += $${libforma_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libforma_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libforma_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libforma_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${libforma_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libforma_HEADERS} \

# SOURCES
#
SOURCES += \
$${libforma_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################


