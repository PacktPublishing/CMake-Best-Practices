#!/bin/bash

# https://stackoverflow.com/questions/39316303/get-dev-library-packages-for-arm-on-x64-ubuntu-host

set -e

PACKAGES="libc6 libc6-dev libstdc++-10-dev libstdc++6 build-essential g++-10 gcc-10 libgcc-10-dev libgcc-s1  linux-libc-dev"

SYSROOT_DIR=$(pwd)/sysroot
STAGING_DIR=$(pwd)/staging

DL_DIR=$(mktemp -d)

echo "Downloading packages to ${DL_DIR}"
cd ${DL_DIR}
for p in $PACKAGES; do
	apt-get download $p
done
cd -

echo "Extraging packages to sysroot: ${SYSROOT_DIR}"
for deb in ${DL_DIR}/*.deb; do
	dpkg-deb -x $deb ./sysroot
done

echo "Writing toolchain file "
cat << EOF > ./toolchain.cmake
set(CMAKE_SYSROOT ${SYSROOT_DIR}) 

set(CMAKE_STAGING_PREFIX ${STAGING_DIR}) 

set(CMAKE_C_COMPILER ${CMAKE_SYSROOT}/usr/bin/gcc-10) 
set(CMAKE_CXX_COMPILER ${CMAKE_SYSROOT}/usr/bin/g++-10) 

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER) 
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY) 
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY) 
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
EOF