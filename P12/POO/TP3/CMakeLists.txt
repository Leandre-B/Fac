cmake_minimum_required(VERSION 3.31.0)
project(TP3 LANGUAGES CXX)

add_executable(TP3
    main.cpp
    tailleposition.cpp
)

target_compile_features(TP3 PUBLIC cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
target_compile_options(TP3 PRIVATE -Wall -Wpedantic)
endif()
