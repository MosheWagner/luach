# -------------------------------------------------
# Project created by QtCreator 2009-09-16 10:15:09
# Author: moshe.wagner@gmail.com
# -------------------------------------------------
TARGET = QLuach
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    daybutton.cpp \
    functions.cpp \
    mhdate.cpp \
    changelocation.cpp
HEADERS += mainwindow.h \
    daybutton.h \
    functions.h \
    mhdate.h \
    changelocation.h
FORMS += mainwindow.ui \
    changelocation.ui
LIBS += -lhdate
RESOURCES += QLuach.qrc
