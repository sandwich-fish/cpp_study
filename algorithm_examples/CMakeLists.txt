cmake_minimum_required(VERSION 3.28)
project(algorithm_examples)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm_examples main.cpp
        algostuff.h
        algo.h
        algo.cpp)
