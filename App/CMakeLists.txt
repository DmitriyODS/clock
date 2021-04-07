cmake_minimum_required(VERSION 3.17)
project(App)

set(CMAKE_CXX_STANDARD 20)

set(SRC App.cpp App.h)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

include_directories(../Activity)

include_directories(../Store)

add_library(
        ${PROJECT_NAME}
        ${SRC}
)

target_link_libraries(
        ${PROJECT_NAME}
        Store Activity
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        sfml-network
)
