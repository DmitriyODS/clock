cmake_minimum_required(VERSION 3.17)
project(Store)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

set(STORE reducers.cpp reducers.h Store.cpp Store.h Action.cpp Action.h State.cpp Store.h)

set(
        APP

        App/actions/actions.cpp
        App/actions/actions.h

        App/reducer/reducer.cpp
        App/reducer/reducer.h

        App/State/State.cpp
        App/State/State.h
)

set(
        MAIN_MENU
)

set(
        CLOCK
)

set(
        CLOCK_ALARM
)

set(
        TIMER
)

set(
        STOPWATCH
)

add_library(
        ${PROJECT_NAME}
        ${APP}
        ${MAIN_MENU}
        ${CLOCK}
        ${CLOCK_ALARM}
        ${TIMER}
        ${STOPWATCH}
)
