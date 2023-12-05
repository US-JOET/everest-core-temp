#!/bin/sh

#apk update && apk add gcovr gtest-dev && apk add --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/ lcov

cmake \
    -B build \
    -S "$EXT_MOUNT/source" \
    -G Ninja \
    -DBUILD_TESTING=ON \
    -DEVC_ENABLE_CCACHE=1 \
    -DISO15118_2_GENERATE_AND_INSTALL_CERTIFICATES=OFF \
    -DCMAKE_INSTALL_PREFIX="$WORKSPACE_PATH/dist"

# ninja -j$(nproc) -C build tests
ninja -j$(nproc) -C build install

# install everestpy via cmake target from everest-framework
ninja -C build everestpy_pip_install_dist

rsync -a "$EXT_MOUNT/source/tests" ./

rm -rf build
