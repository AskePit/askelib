# function tries to find askelib.config file somwhere near askelib folder
defineReplace(findAskelibConfig) {
    for(level, 1..4) {
        level_str = $$level_str"/.."
        path = $$PWD$${level_str}/askelib.config
        exists( $$clean_path($$path) ) {
            #message("found askelib.config!")
            return($$path)
        }
    }

    return("")
}

!defined(VLC_PATH) {
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
                    VLC_PATH = $$clean_path($$t)
                    #message("libvlc is defined here: $${VLC_PATH}")
                    LIBS += -L$${VLC_PATH}/lib -llibvlccore -llibvlc
                }
            }
        }
    }
}
