include( ../common.pri )

QT += core gui widgets

TEMPLATE = lib
CONFIG += staticlib
TARGET = askelib_widgets$${ASKE_LIB_SUFFIX}

# for std/ includes
INCLUDEPATH += ..

unset(VLC_PATH)

askelib_config = $$findAskelibConfig()

# parse askelib.config file in case of it's presence
!isEmpty(askelib_config) {
    lines = $$cat($$askelib_config, lines)
    for (line, lines) {
        # vlc_use option
        t = $$lower( $$replace(line, "^vlc_use\\s*=\\s*(\\S+)$", "\\1") )
        !isEqual(t, $$line) {
            # vlc_path option
            t = $$replace(line, "^vlc_path\\s*=\\s*(\\S+)$", "\\1")
            !isEqual(t, $$line) {
                DEFINES *= ASKELIB_USE_VLC
                VLC_PATH = $$t
                message("libvlc is defined here: $${VLC_PATH}")
                INCLUDEPATH += $${VLC_PATH}/include
                LIBS += -L$${VLC_PATH}/lib -llibvlccore -llibvlc
            }
        }
    }
}

include( texteditor/texteditor.pri )
include( mediawidget/mediawidget.pri )
