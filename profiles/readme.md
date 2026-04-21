## Prerequisites (system)

**Debian/Ubuntu:**
sudo apt install libopencv-dev pkg-config cmake

**Fedora/RHEL:**
sudo dnf install opencv-devel pkgconf-pkg-config cmake

## Build

    pip install conan --upgrade
    conan install . --output-folder=build --profile=profiles/linux-debug --build=missing
    cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake
    cmake --build build
