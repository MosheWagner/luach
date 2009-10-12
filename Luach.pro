# -------------------------------------------------
# Project created by QtCreator
# Author: moshe.wagner@gmail.com
# -------------------------------------------------
TARGET = Luach
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
    LIBS += -lintl -LC:\libhdate\lib
    INCLUDEPATH += C:\libhdate\include
}

RESOURCES += Luach.qrc


# Install binaries
binary.path = /usr/local/bin/
binary.files = Luach

# Install ZmanimCLI
zmanim.path = /usr/local/bin/
zmanim.files = ZmanimCLI.jar

INSTALLS += binary
INSTALLS += zmanim
