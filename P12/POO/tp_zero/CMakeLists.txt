cmake_minimum_required(VERSION 3.16)

project(tp_zero LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tp_zero
    main.cpp
    const.cpp
    const.hpp
)

target_compile_features(tp_zero PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tp_zero PRIVATE -Wall -Wpedantic)
endif()
