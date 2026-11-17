cmake_minimum_required(VERSION 3.31)
project(TP-3-5 LANGUAGES CXX)

find_package(SFML COMPONENTS graphics window system)

add_executable(TP-3-5
    main.cc
    position.hh
    taille.hh
    objet.hh
    objectactif.hh
    joueur.hh
    invader.hh
    projectile.hh
    jeu.hh
)

target_link_libraries(TP-3-5 PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(TP-3-5 PRIVATE cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(TP-3-5 PRIVATE -Wall -Wpedantic -g)
endif()

