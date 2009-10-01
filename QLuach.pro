# -------------------------------------------------
# Project created by QtCreator
# Author: moshe.wagner@gmail.com
# -------------------------------------------------
TARGET = QLuach
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
RESOURCES += QLuach.qrc
