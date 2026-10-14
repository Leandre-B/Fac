cmake_minimum_required(VERSION 3.16)

project(tp_un LANGUAGES CXX)

add_executable(tp_un
    main.cc
    sequence.hh
    sequence.cc
)

target_compile_features(tp_un PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tp_un PRIVATE -Wall -Wpedantic)
endif()
