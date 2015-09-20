# TODO add tests if any

TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    src \
    app \
#    tests

app.depends = src
#tests.depends = src
