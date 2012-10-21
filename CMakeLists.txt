cmake_minimum_required(VERSION 2.8)
project(tvorba)

set(tvorba_VERSION_MAJOR 1)
set(tvorba_VERSION_MINOR 0)

configure_file
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_executable(tvorba ${SOURCES})
