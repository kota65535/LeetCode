cmake_minimum_required(VERSION 3.15)
project(_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(_10 main.cpp Automaton.cpp Automaton.h Parser.cpp Parser.h)