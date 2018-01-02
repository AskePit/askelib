TEMPLATE = subdirs

SUBDIRS += \
    std \
    widgets \
    tests

std.subdir = std
widgets.subdir = widgets
tests.subdir = tests

widgets.depends = std
tests.depends = std
