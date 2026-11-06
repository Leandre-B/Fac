cmake_minimum_required(VERSION 3.31)
project(tp3_3_carte LANGUAGES CXX)

find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(tp3_3_carte
    element.cpp element.hpp
    tailleposition.cpp tailleposition.hpp
    carte.cpp carte.hpp
    personnage.cpp personnage.hpp
    obstacle.cpp obstacle.hpp
    objetramassable.cpp objetramassable.hpp
    main.cpp
)
target_compile_features(tp3_3_carte PUBLIC cxx_std_17)
target_compile_options(tp3_3_carte PRIVATE -Wall -Wpedantic)


# add_executable(tp3_3_carte_sfml
#     element.cc tailleposition.cc carte.cc affichage_carte.cc main_sfml.cc)
# target_link_libraries(tp3_3_carte_sfml PRIVATE sfml-graphics sfml-window sfml-system)
# target_compile_features(tp3_3_carte_sfml PRIVATE cxx_std_17)
# target_compile_options(tp3_3_carte_sfml PRIVATE -Wall -Wpedantic)
