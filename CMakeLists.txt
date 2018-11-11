cmake_minimum_required(VERSION 3.10)
project(PistacheTest)

set(CMAKE_CXX_STANDARD 17)

option(PISTACHE_INSTALL OFF)
add_subdirectory(pistache)

add_executable(PistacheTest main.cpp)

target_link_libraries(PistacheTest pistache)