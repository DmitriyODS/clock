cmake_minimum_required(VERSION 3.17)
project(global)

set(CMAKE_CXX_STANDARD 20)

set(GLOB_TYPES globalTypes.cpp globalTypes.h config.h paths.h)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

add_library(
        ${PROJECT_NAME}
        ${GLOB_TYPES}
)
