cmake_minimum_required(VERSION 3.0.0)
project(processA VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(processB main.cpp)
add_library(pipe STATIC IMPORTED)
add_library(messageQueue STATIC IMPORTED)
add_library(sharedMemory STATIC IMPORTED)
add_library(fileMapping STATIC IMPORTED)
add_library(socket STATIC IMPORTED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(pipe PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../pipe)
set_target_properties(pipe PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../pipe/build/libpipe.a)
target_link_libraries(processB pipe)

set_target_properties(messageQueue PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../messageQueue)
set_target_properties(messageQueue PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../messageQueue/build/libmessageQueue.a)
target_link_libraries(processB messageQueue)

set_target_properties(sharedMemory PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../sharedMemory)
set_target_properties(sharedMemory PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../sharedMemory/build/libsharedMemory.a)
target_link_libraries(processB sharedMemory)

set_target_properties(fileMapping PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../fileMapping)
set_target_properties(fileMapping PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../fileMapping/build/libfileMapping.a)
target_link_libraries(processB fileMapping)

set_target_properties(socket PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/../socket)
set_target_properties(socket PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../socket/build/libsocket.a)
target_link_libraries(processB socket)