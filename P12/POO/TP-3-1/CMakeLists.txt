cmake_minimum_required(VERSION 3.16)

project(TP-3-1 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(Catch2 URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.7.1.zip )
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
enable_testing()


# Test
add_executable(TP-3-1_test
    tailleposition.cpp
    tailleposition.hpp
    element.hpp
    element.cpp
    main_test.cpp
    personnage.hpp personnage.cpp
    objetramassable.hpp objetramassable.cpp
    obstacle.hpp obstacle.cpp
)

target_compile_features(TP-3-1_test PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(TP-3-1_test PRIVATE -Wall -Wpedantic)
endif()
target_link_libraries(TP-3-1_test PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(TP-3-1_test)
# Fin Test


