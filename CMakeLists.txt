
cmake_minimum_required(VERSION 3.21)

project(topng)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_definitions ("-Wall")
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(topng ${PROJECT_SOURCE_DIR}/main.cpp pngcrypt.cpp)
target_link_libraries(topng png)
