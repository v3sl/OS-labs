cmake_minimum_required(VERSION 3.0.0)
project(Vector VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

add_library(Vector SHARED vector.cpp)

add_library(Number STATIC IMPORTED)
set_target_properties(Number PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../Number)
set_target_properties(Number PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Number/build/libNumber.a)
target_link_libraries(Vector Number)