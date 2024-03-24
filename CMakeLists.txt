cmake_minimum_required(VERSION 3.28)
project(DeepCover)

set(CMAKE_CXX_STANDARD 17)

add_executable(deepcover main.cpp
        Injector/AbstractInjector.cpp
        Injector/GenericInjector.cpp
        Extractor/AbstractExtractor.cpp
        Extractor/GenericExtractor.cpp
        Injector/BMPInjector.cpp
        Extractor/BMPExtractor.cpp
        Extractor/Extractor.hpp
        Injector/Injector.hpp
        selector.cpp
        selector.hpp
        GenericHandler.cpp
        GenericHandler.hpp
)
