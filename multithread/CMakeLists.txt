cmake_minimum_required(VERSION 3.8)
project(mini_thread)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(mini_thread ${SOURCE_FILES})
set(CMAKE_CXX_FLAGS "-pthread")
