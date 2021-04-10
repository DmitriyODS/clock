cmake_minimum_required(VERSION 3.17)
project(Components)

set(CMAKE_CXX_STANDARD 20)

set(SRC BaseComponent.cpp BaseComponent.h)

set(
        LOADING_SCREEN

        LoadingScreen/LoadingScreen.cpp
        LoadingScreen/LoadingScreen.h
)

set(
        MENU

        Menu/Menu.cpp
        Menu/Menu.h
)

set(
        BUTTON

        Button/Button.cpp
        Button/Button.h
)

set(
        CLOCK

        Clock/Clock.cpp
        Clock/Clock.h
)

set(
        ALARM_CLOCK

        AlarmClock/AlarmClock.cpp
        AlarmClock/AlarmClock.h
)

set(
        TIMER

        Timer/Timer.cpp
        Timer/Timer.h
)

set(
        STOPWATCH

        Stopwatch/Stopwatch.cpp
        Stopwatch/Stopwatch.h
)

set(
        CARD_NOT_FOUND

        CardNotFound/CardNotFound.cpp
        CardNotFound/CardNotFound.h
)

set(
        SETTINGS

        Settings/Settings.cpp
        Settings/Settings.h
)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

include_directories(../global)

add_library(
        ${PROJECT_NAME}
        ${SRC}
        ${LOADING_SCREEN}
        ${MENU}
        ${BUTTON}
        ${CLOCK}
        ${TIMER}
        ${STOPWATCH}
        ${ALARM_CLOCK}
        ${CARD_NOT_FOUND}
        ${SETTINGS}
)

target_link_libraries(${PROJECT_NAME} global)
