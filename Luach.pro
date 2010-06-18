# -------------------------------------------------
# Project created by QtCreator
# Author: moshe.wagner@gmail.com
# -------------------------------------------------
TARGET = luach
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    daybutton.cpp \
    functions.cpp \
    mhdate.cpp \
    changelocation.cpp \
    about.cpp
HEADERS += mainwindow.h \
    daybutton.h \
    functions.h \
    mhdate.h \
    changelocation.h \
    about.h
FORMS += mainwindow.ui \
    changelocation.ui \
    about.ui
LIBS += -lhdate
win32 { 
    LIBS += -lintl \
        -LC:\libhdate\lib
    INCLUDEPATH += C:\libhdate\include
}
RESOURCES += Luach.qrc
TRANSLATIONS = Hebrew.ts

# Install binaries
target.path = /usr/bin/

# Install ZmanimCLI
zmanim.path = /usr/share/Luach/
zmanim.files = ZmanimCLI.jar

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
INSTALLS += icon
INSTALLS += menu
