#! /bin/zsh
cd $1
cmake \
    -S . \
    -B build \
    -DCMAKE_TOOLCHAIN_FILE=./cmake/gcc-arm-none-eabi.cmake \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -G "Ninja" \
    -DCMAKE_BUILD_TYPE=Debug 
cmake --build build
cd -
