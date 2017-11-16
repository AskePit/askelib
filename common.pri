include( public.pri )

DESTDIR = $${ASKE_LIB_PATH}

defineReplace(findAskelibConfig) {
    for(level, 1..4) {
        level_str += /..
        path = $$PWD$${level_str}/askelib.config
        exists($${path}) {
            return($${path})
        }
    }

    return("")
}
