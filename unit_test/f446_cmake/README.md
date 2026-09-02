# Hướng dẫn build dự án bằng CMake cho STM32F446RET trong môi trường Unix

## Chuẩn bị
1. Tải và cài đặt GNU ARM toolchain 
Tải toolchain tại [GNU ARM toolchain](https://gitlab.arm.com/tooling/gnu-toolchains-for-arm) và lựa chọn phiên bản trong nhánh release tương ứng
2. Cài đặt Ninja
    - Sử dụng package manager là brew `brew install ninja`
    - Sử dụng package manager là apt `sudo apt install ninja-build`
## Thực hiện
1. Thêm đường dẫn toolchain vào biến môi trường $PATH
Sử dụng lệnh bên dưới để thêm đường dẫn toolchain vào đường dẫn chung PATH:
    ```bash
    export PATH="$PATH:$HOME/arm-gnu-toolchain-*/bin"
    ```
2. Build dự án với CMake sử dụng mẫu bên dưới:
    ```bash
    cd <target project>
    cmake \
        -S . \
        -B build \
        -DCMAKE_TOOLCHAIN_FILE=./cmake/gcc-arm-none-eabi.cmake \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -G "Ninja" \
        -DCMAKE_BUILD_TYPE=Debug 
    cmake --build build
    ```
