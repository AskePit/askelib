CONFIG(debug, debug|release) {
    ASKELIB_BUILD_FLAG = debug
    ASKELIB_LIB_SUFFIX = d
} else {
    ASKELIB_BUILD_FLAG = release
}

ASKELIB_LIB_PATH = $$PWD/libs/
ASKELIB_INCLUDE_PATH = $$PWD
