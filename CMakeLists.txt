cmake_minimum_required(VERSION 3.17)
project(Clock)

set(CMAKE_CXX_STANDARD 20)

include_directories(Store)

include_directories(global)

include_directories(App)

include_directories(Activity)

include_directories(daemons)

add_subdirectory(daemons)

add_subdirectory(Activity)

add_subdirectory(App)

add_subdirectory(global)

add_subdirectory(Store)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/lib/cmake/SFML")

set(SRC)

file(GLOB ALL_REQUIRED_DLL "SFML/bin/*.dll")

file(COPY ${ALL_REQUIRED_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${SRC})

target_link_libraries(
        ${PROJECT_NAME}
        Store
        global
        App
        Activity
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        sfml-network
        daemons
)
