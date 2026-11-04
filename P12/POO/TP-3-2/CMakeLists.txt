cmake_minimum_required(VERSION 3.16)

project(TP-3-2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP-3-2 main.cpp
    couleur.hpp
    point.hpp point.cpp
    figuregeometrique.hpp figuregeometrique.cpp
    main_test.cpp)

include(GNUInstallDirs)
install(TARGETS TP-3-2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
