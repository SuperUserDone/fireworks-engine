cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_TOOLCHAIN_FILE "./vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")


project(SpaceGame CXX)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

find_package(SDL2 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_subdirectory(src)
