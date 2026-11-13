

cmake_minimum_required(VERSION 3.31)
project(tp3_3_carte LANGUAGES CXX)

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(tp3_3_carte
    element.cpp element.hh
    tailleposition.cpp tailleposition.hh
    carte.cpp carte.hh
    personnage.cpp personnage.hh
    obstacle.cpp obstacle.hh
    objetramassable.cpp objetramassable.hh
    main.cpp)
target_compile_features(tp3_3_carte PUBLIC cxx_std_17)
target_compile_options(tp3_3_carte PRIVATE -Wall -Wpedantic)

add_executable(tp3_3_carte_sfml     element.cpp element.hh
    tailleposition.cpp tailleposition.hh
    carte.cpp carte.hh
    personnage.cpp personnage.hh
    obstacle.cpp obstacle.hh
    objetramassable.cpp objetramassable.hh
    main_sfml.cc
    affichage_carte.cc
    affichage_carte.hh)
target_link_libraries(tp3_3_carte_sfml PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(tp3_3_carte_sfml PRIVATE cxx_std_17)
target_compile_options(tp3_3_carte_sfml PRIVATE -Wall -Wpedantic)

