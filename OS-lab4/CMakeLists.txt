cmake_minimum_required(VERSION 3.0.0)
project(OS-lab4 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(OS-lab4 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
