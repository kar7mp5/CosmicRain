cmake_minimum_required(VERSION 3.16)

project(main C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG f6864924f76e1a0b4abaefc76ae2ed22b1a8916e
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SDL3)

set(SOURCES
    src/main.c
)
add_executable(main ${SOURCES})

target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE SDL3::SDL3)