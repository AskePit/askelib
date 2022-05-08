include( ../common.pri )

DESTDIR = $${ASKELIB_LIB_PATH}

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_std$${ASKELIB_LIB_SUFFIX}

# Input
HEADERS += \
    mask.h \
    money.h \
    tree.h \
    rvector.h \

SOURCES += \
    money.cpp \
