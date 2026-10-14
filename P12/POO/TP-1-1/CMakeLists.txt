cmake_minimum_required(VERSION 3.31.0)
project(TP-1-1 LANGUAGES CXX)

add_executable(TP-1-1 
    main.cc
    sequence.cc    
)
target_compile_features(TP-1-1 PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TP-1-1 PRIVATE -Wall -Wpedantic)
endif()