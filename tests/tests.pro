include( ../public.pri )

TEMPLATE = app

# Input
SOURCES += \
    tests.cpp

INCLUDEPATH += $$ASKE_INCLUDE_PATH
LIBS += -L$${ASKE_LIB_PATH} -laskelib_std$${ASKE_LIB_SUFFIX}
