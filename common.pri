include( public.pri )

DESTDIR = $${ASKE_LIB_PATH}

# function tries to find askelib.config file somwhere near askelib folder
defineReplace(findAskelibConfig) {
    for(level, 1..4) {
        level_str = $$level_str"/.."
        path = $$PWD$${level_str}/askelib.config
        exists( $$clean_path($$path) ) {
            message("found askelib.config!")
            return($$path)
        }
    }

    return("")
}
