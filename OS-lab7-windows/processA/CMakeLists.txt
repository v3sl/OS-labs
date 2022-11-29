cmake_minimum_required(VERSION 3.0.0)
project(processA VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(processA main.cpp)
add_library(pipe STATIC IMPORTED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(pipe PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../pipe)
set_target_properties(pipe PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../pipe/build/Debug/pipe.lib)
target_link_libraries(processA pipe)