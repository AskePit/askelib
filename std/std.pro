include( ../common.pri )

DESTDIR = $${ASKE_LIB_PATH}

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_std$${ASKE_LIB_SUFFIX}

# Input
HEADERS += \
    opt.h \
    mask.h \
    fs.h \
    money.h \
    tree.h \
    rvector.h \
    pitm/pitmarray.h \
    pitm/pitmdocument.h \
    pitm/pitmobject.h \
    pitm/pitmvalue.h

SOURCES += \
    fs.cpp \
    money.cpp \
    pitm/pitmarray.cpp \
    pitm/pitmdocument.cpp \
    pitm/pitmobject.cpp \
    pitm/pitmvalue.cpp \
    pitm/pitmparser.cpp \
    pitm/pitmwriter.cpp \
    pitm/pitm.cpp
