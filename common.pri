CONFIG(debug, debug|release) {
    BUILD_FLAG = debug
    LIB_SUFFIX = d
} else {
    BUILD_FLAG = release
}

DESTDIR = $$PWD/libs/
INCLUDEPATH *= $$PWD/libs/
LIBS *= -L$$PWD
