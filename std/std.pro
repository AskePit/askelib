include( ../common.pri )

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_std$${ASKE_LIB_SUFFIX}

# Input
HEADERS += opt.h \
	mask.h \
    fs.h

SOURCES += \
    fs.cpp
