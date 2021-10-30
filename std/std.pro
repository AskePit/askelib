include( ../common.pri )

DESTDIR = $${ASKE_LIB_PATH}

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_std$${ASKE_LIB_SUFFIX}

# Input
HEADERS += \
    mask.h \
    money.h \
    tree.h \
    rvector.h \

SOURCES += \
    money.cpp \
