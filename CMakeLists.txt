cmake_minimum_required(VERSION 3.14)
project(OpenGLSamples CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG 3.3.7
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
    glew
    URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
    SOURCE_SUBDIR build/cmake
)
set(BUILD_UTILS OFF CACHE BOOL "")
FetchContent_MakeAvailable(glew)
include_directories(${glew_SOURCE_DIR}/include)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
)
FetchContent_MakeAvailable(glm)

find_package(OpenGL REQUIRED)

add_subdirectory(create_window)