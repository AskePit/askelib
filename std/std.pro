include( ../common.pri )

DESTDIR = $${ASKE_LIB_PATH}

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_std$${ASKE_LIB_SUFFIX}

# Input
HEADERS += opt.h \
	mask.h \
    fs.h \
    money.h \
    tree.h

SOURCES += \
    fs.cpp \
    money.cpp
