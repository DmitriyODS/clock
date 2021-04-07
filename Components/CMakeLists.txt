cmake_minimum_required(VERSION 3.17)
project(Components)

set(CMAKE_CXX_STANDARD 20)

set(SRC BaseComponent.cpp BaseComponent.h)

set(
        LOADING_SCREEN

        LoadingScreen/LoadingScreen.cpp
        LoadingScreen/LoadingScreen.h
)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

include_directories(../global)

add_library(
        ${PROJECT_NAME}
        ${SRC}
        ${LOADING_SCREEN}
)

target_link_libraries(${PROJECT_NAME} global)
