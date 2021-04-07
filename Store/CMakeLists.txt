cmake_minimum_required(VERSION 3.17)
project(Store)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

set(STORE reducers.cpp reducers.h Store.cpp Store.h Action.cpp Action.h State.cpp State.h)

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

        MainMenu/actions/actions.cpp
        MainMenu/actions/actions.h

        MainMenu/reducer/reducer.cpp
        MainMenu/reducer/reducer.h

        MainMenu/State/State.cpp
        MainMenu/State/State.h
)

set(
        CLOCK

        Clock/actions/actions.cpp
        Clock/actions/actions.h

        Clock/reducer/reducer.cpp
        Clock/reducer/reducer.h

        Clock/State/State.cpp
        Clock/State/State.h
)

set(
        ALARM_CLOCK

        AlarmClock/actions/actions.cpp
        AlarmClock/actions/actions.h

        AlarmClock/reducer/reducer.cpp
        AlarmClock/reducer/reducer.h

        AlarmClock/State/State.cpp
        AlarmClock/State/State.h
)

set(
        TIMER

        Timer/actions/actions.cpp
        Timer/actions/actions.h

        Timer/reducer/reducer.cpp
        Timer/reducer/reducer.h

        Timer/State/State.cpp
        Timer/State/State.h
)

set(
        STOPWATCH

        Stopwatch/actions/actions.cpp
        Stopwatch/actions/actions.h

        Stopwatch/reducer/reducer.cpp
        Stopwatch/reducer/reducer.h

        Stopwatch/State/State.cpp
        Stopwatch/State/State.h
)

add_library(
        ${PROJECT_NAME}
        ${STORE}
        ${APP}
        ${MAIN_MENU}
        ${CLOCK}
        ${ALARM_CLOCK}
        ${TIMER}
        ${STOPWATCH}
)
