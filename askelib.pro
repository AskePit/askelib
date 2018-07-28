TEMPLATE = subdirs

SUBDIRS += \
    std \
    tests

std.subdir = std
tests.subdir = tests

tests.depends = std
