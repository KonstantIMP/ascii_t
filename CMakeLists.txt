cmake_minimum_required(VERSION 3.5)

project(ascii_t LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ascii_t src/main.cpp include/defines.hpp)

install(TARGETS ascii_t DESTINATION "/usr/bin")
