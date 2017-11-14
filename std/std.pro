TEMPLATE = lib
CONFIG += staticlib
TARGET = std

# Input
HEADERS += opt.h \
	mask.h \
    fs.h

SOURCES += \
    fs.cpp