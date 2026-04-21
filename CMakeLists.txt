cmake_minimum_required(VERSION 3.25)

Project(
    Grimoire
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "Real-time webcam to ASCII art with truecolor terminal output"
    HOMEPAGE_URL "https://github.com/Grimmoroth/Grimoire.git"
)

if(CMAKE_SOURCEDIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR
        "In-source builds are not allowed.\n"
        "Create a build directory and run CMake from there:\n"
        "  cmake --preset conan-debug\n"
        "Remove CMakeCache.txt and CMakeFiles/ if they were created."
    )
endif()


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXSTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(cmake/CompilerWarnings.cmake)
include(cmake/ClangTidy.cmake)

find_package(PkgConfig REQUIRED)
pkg_check_modules(OpenCV REQUIRED opencv4)

find_package(fmt    REQUIRED)
find_package(spdlog REQUIRED)

add_subdirectory(libs/core)

add_subdirectory(apps/terminal)
add_subdirectory(apps/virtual_cam)