cmake_minimum_required(VERSION 3.28)
project(DeepCover)

set(CMAKE_CXX_STANDARD 17)

add_executable(deepcover main.cpp
        selector.cpp
        selector.hpp
        Handler/GenericHandler.cpp
        Handler/Handler.hpp
        Handler/BMPHandler.cpp
)
