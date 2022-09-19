cmake_minimum_required(VERSION 3.0.0)
project(testLibs)

set(CMAKE_CXX_STANDARD 14)

add_executable(testLibs main.cpp)

add_library(Number STATIC IMPORTED)
set_target_properties(Number PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../Number)
set_target_properties(Number PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Number/build/libNumber.a)
target_link_libraries(testLibs Number)

add_library(Vector SHARED IMPORTED)
set_target_properties(Vector PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../Vector)
set_target_properties(Vector PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../Vector/build/libVector.so)
target_link_libraries(testLibs Vector)