# -------------------------------------------------
# Project created by QtCreator
# Author: moshe.wagner@gmail.com
# -------------------------------------------------
TARGET = luach
TEMPLATE = app
CONFIG += qt
QT += gui widgets printsupport core
SOURCES += main.cpp \
    mainwindow.cpp \
    daybutton.cpp \
    functions.cpp \
    mhdate.cpp \
    about.cpp \
    settings.cpp \
    dialog.cpp
HEADERS += mainwindow.h \
    daybutton.h \
    functions.h \
    mhdate.h \
    about.h \
    settings.h \
    dialog.h
FORMS += mainwindow.ui \
    settings.ui \
    dialog.ui \
    about.ui

LIBS += -lhdate

win32 { 
    LIBS += -lintl \
        -LC:\libhdate\lib
    INCLUDEPATH += C:\libhdate\include
}
else:unix{
   QMAKE_CFLAGS_RELEASE+=$(shell dpkg-buildflags --get CFLAGS) $(shell dpkg-buildflags --get CPPFLAGS)
   QMAKE_CFLAGS_DEBUG+=$(shell dpkg-buildflags --get CFLAGS) $(shell dpkg-buildflags --get CPPFLAGS)
   QMAKE_CXXFLAGS_RELEASE+=$(shell dpkg-buildflags --get CFLAGS) $(shell dpkg-buildflags --get CPPFLAGS)
   QMAKE_CXXFLAGS_DEBUG+=$(shell dpkg-buildflags --get CFLAGS)
   QMAKE_CXXFLAGS_DEBUG+=$(shell dpkg-buildflags --get CPPFLAGS)
   QMAKE_LFLAGS_RELEASE+=$(shell dpkg-buildflags --get LDFLAGS)
   QMAKE_LFLAGS_DEBUG+=$(shell dpkg-buildflags --get LDFLAGS)
}

RESOURCES += Luach.qrc
TRANSLATIONS = Hebrew.ts

# Install binaries
target.path = /usr/bin/

# Install ZmanimCLI
zmanim.path = /usr/share/java/
zmanim.files = ZmanimCLI.jar

# Install zanimcli script
zmanimcli.path = /usr/bin/
zmanimcli.files = zmanimcli

# Install Icons:
icon.path = /usr/share/Luach/
icon.files = Icons/calendar.png

# Install shortcut
menu.path = /usr/share/applications
menu.files = Luach.desktop

# Install translation
trans.path = /usr/share/Luach/
trans.files = Hebrew.qm
INSTALLS += target
INSTALLS += trans
INSTALLS += zmanim
INSTALLS += zmanimcli
INSTALLS += icon
INSTALLS += menu
