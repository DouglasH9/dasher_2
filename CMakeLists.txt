cmake_minimum_required(VERSION 3.25)
project(dapper_dasher)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FETCHCONTENT_DECLARE(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG "master"
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FETCHCONTENT_MAKEAVAILABLE(raylib)


add_executable(dapper_dasher main.cpp constants.h classes/Scarfy.cpp classes/Scarfy.h)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_subdirectory(textures)
add_subdirectory(classes)
