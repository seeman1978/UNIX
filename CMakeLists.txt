cmake_minimum_required(VERSION 3.19)
project(UNIX)

set(CMAKE_CXX_STANDARD 20)

include_directories(/Users/wq/Downloads/apue.3e/include)

add_executable(UNIX fork.cpp)