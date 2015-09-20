#!/bin/bash

cd /vagrant
mkdir shadow_build
cd shadow_build
qmake ../qGPG.pro
make

rm -rf "/vagrant/release/$1"
mkdir "/vagrant/release/$1"

# TODO create a debian package
# TODO copy the debian package to release/$system folder

cd /vagrant
rm -rf shadow_build
