#!/bin/bash

source scripts/cprint.sh

LINUX_SYSTEMS=( linux32 linux64 )

# Run the deployment on GNU/Linux
for system in "${LINUX_SYSTEMS[@]}"
do
  cprint YELLOW "Starting deployment for $system ...\n"
  vagrant up "$system"

  # TODO add deployment/build script here

  vagrant halt "$system"
done

# Run the deployment on OS X
cprint YELLOW "Starting deployment for osx ...\n"
vagrant up osx

# TODO add deployment/build script here

vagrant halt osx
