include( ../common.pri )
include( ../config.pri )

DESTDIR = $${ASKE_LIB_PATH}

QT += core gui widgets

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_widgets$${ASKE_LIB_SUFFIX}

# for std/ includes
INCLUDEPATH += ..

include( texteditor/texteditor.pri )
include( mediawidget/mediawidget.pri )

!isEmpty(VLC_PATH) {
    INCLUDEPATH += $${VLC_PATH}/include
}
