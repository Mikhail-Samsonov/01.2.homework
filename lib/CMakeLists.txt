cmake_minimum_required(VERSION 3.10)

project(Library)

add_library(lib STATIC lib.cpp)

set_target_properties(
        lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        lib 
        PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)