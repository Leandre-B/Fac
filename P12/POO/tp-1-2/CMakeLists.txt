cmake_minimum_required(VERSION 3.16)

project(tp-1-2 LANGUAGES CXX)

add_executable(tp-1-2 main.cpp)

target_compile_features(tp-1-2 PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tp-1-2 PRIVATE -Wall -Wpedantic)
endif()


