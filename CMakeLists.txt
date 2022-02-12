cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_TOOLCHAIN_FILE "./vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")


project(fireworks-engine CXX)

find_package(SDL2 CONFIG REQUIRED)

add_executable(test_exe main.cpp)

target_link_libraries(test_exe PRIVATE SDL2::SDL2 SDL2::SDL2main)