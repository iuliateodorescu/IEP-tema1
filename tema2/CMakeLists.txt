cmake_minimum_required(VERSION 3.2)

project(tema2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tema2 main.cpp)

install(TARGETS tema2 DESTINATION bin)