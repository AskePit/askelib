QT += core gui widgets

TEMPLATE = lib
CONFIG += staticlib
TARGET = widgets

# Input
SOURCES += texteditor/texteditor.cpp \
    texteditor/highlighters/clike.cpp \
    texteditor/highlighters/cplusplus.cpp \
    texteditor/highlighters/ini.cpp \
    texteditor/highlighters/js.cpp \
    texteditor/highlighters/python.cpp \
    texteditor/highlighters/rust.cpp \
    texteditor/highlighters/shell.cpp \
    texteditor/highlighters/tab.cpp \
    texteditor/syntax.cpp

HEADERS  += texteditor/texteditor.h \
    texteditor/highlighters/clike.h \
    texteditor/highlighters/cplusplus.h \
    texteditor/highlighters/ini.h \
    texteditor/highlighters/js.h \
    texteditor/highlighters/python.h \
    texteditor/highlighters/rust.h \
    texteditor/highlighters/shell.h \
    texteditor/highlighters/tab.h \
    texteditor/highlighters/highlighters.h \
    texteditor/syntax.h

INCLUDEPATH += ..
