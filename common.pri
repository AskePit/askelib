CONFIG(debug, debug|release) {
    ASKE_BUILD_FLAG = debug
    ASKE_LIB_SUFFIX = d
} else {
    ASKE_BUILD_FLAG = release
}

ASKE_LIB_PATH = $$PWD/libs/
ASKE_INCLUDE_PATH = $$PWD
