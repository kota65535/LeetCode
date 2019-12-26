cmake_minimum_required(VERSION 3.15)
project(_34)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


add_executable(_34 main.cpp)