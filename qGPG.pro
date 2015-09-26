# TODO add tests if any

TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    src \
    app \
    plugins \
    tests

app.depends = src
tests.depends = src
