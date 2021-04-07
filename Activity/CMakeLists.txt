cmake_minimum_required(VERSION 3.17)
project(Activity)

set(CMAKE_CXX_STANDARD 20)

set(
        BASE_ACTIVITY

        BaseActivity.cpp
        BaseActivity.h
)

set(
        LOADING_ACTIVITY

        LoadingActivity/LoadingActivity.cpp
        LoadingActivity/LoadingActivity.h
)

set(
        MAIN_ACTIVITY

        MainActivity/MainActivity.cpp
        MainActivity/MainActivity.h
)

set(
        ALARM_CLOCK_ACTIVITY

        AlarmClockActivity/AlarmClockActivity.cpp
        AlarmClockActivity/AlarmClockActivity.h
)

set(SFML_DIR "../SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(../SFML/include)

include_directories(../Components)

add_library(
        ${PROJECT_NAME}
        ${LOADING_ACTIVITY}
        ${BASE_ACTIVITY}
        ${MAIN_ACTIVITY}
        ${ALARM_CLOCK_ACTIVITY}
)

target_link_libraries(${PROJECT_NAME} Components)
