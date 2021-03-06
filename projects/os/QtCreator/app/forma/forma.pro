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
#   File: forma.pro
#
# Author: $author$
#   Date: 7/1/2018
#
# QtCreator .pro file for forma executable forma
########################################################################
include(../../../../../build/QtCreator/forma.pri)
include(../../../../QtCreator/forma.pri)
include(../../forma.pri)
include(../../../../QtCreator/app/forma/forma.pri)

TARGET = $${forma_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${forma_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${forma_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${forma_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${forma_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${forma_exe_HEADERS} \

# SOURCES
#
SOURCES += \
$${forma_exe_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${forma_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${forma_exe_LIBS} \
$${FRAMEWORKS} \


