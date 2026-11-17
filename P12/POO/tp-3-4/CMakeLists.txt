cmake_minimum_required(VERSION 3.31)
project(tp-3-4 LANGUAGES CXX)

find_package(SFML COMPONENTS graphics window system REQUIRED)


add_executable(tp-3-4
    main.cpp
    sommet.cc
    sommet.hh
)


target_compile_features(tp-3-4 PUBLIC cxx_std_17)
target_compile_options(tp-3-4 PRIVATE -Wall -Wpedantic)
