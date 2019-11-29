include( ../public.pri )

TEMPLATE = app

# Input
SOURCES += \
    tests.cpp

INCLUDEPATH += $$ASKELIB_INCLUDE_PATH
LIBS += -L$${ASKELIB_LIB_PATH} -laskelib_std$${ASKELIB_LIB_SUFFIX}
