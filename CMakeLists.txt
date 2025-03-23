cmake_minimum_required(VERSION 4.0)
project(vulkan_exp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SDL3
FetchContent_Declare(
        sdl3
        GIT_REPOSITORY https://github.com/libsdl-org/sdl.git
        GIT_TAG f6864924f76e1a0b4abaefc76ae2ed22b1a8916e
)
FetchContent_MakeAvailable(sdl3)

# Vulkan
find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} source/main.cpp
        source/core/vulkan_renderer.cpp
        source/core/vulkan_renderer.h
        source/core/window.cpp
        source/core/window.h
        source/core/vulkan_utils.cpp
        source/core/vulkan_utils.h)

target_link_libraries(${PROJECT_NAME} SDL3::SDL3 Vulkan::Vulkan)
