cmake_minimum_required(VERSION 3.2)

project(tema1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tema1 main.cpp)

install(TARGETS tema1 DESTINATION bin)