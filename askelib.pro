TEMPLATE = subdirs

SUBDIRS += \
    std \
    widgets

std.subdir = std
widgets.subdir = widgets

widgets.depends = std
