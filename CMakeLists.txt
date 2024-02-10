cmake_minimum_required(VERSION 3.27)
project(GameEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(vendor)
add_subdirectory(src)