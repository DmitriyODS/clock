#ifndef CLOCK_ACTION_H
#define CLOCK_ACTION_H

/*
 * Храним типы редюсеров
 * нашего приложения
 */
enum class ReducerTypes {
    APP,
    CLOCK,
    ALARM_CLOCK,
    MAIN_MENU,
    STOPWATCH,
    TIMER,
    ALL
};

/*
 * Храним типы событий
 * нашего приложения
 */
enum class ActionTypes {
    INITIAL_STATE,

    //// App
    SET_COLOR_BACKGROUND,
    SET_COLOR_TEXT,
    SET_COLOR_ELEMENTS,
    SET_COLOR_ACCENT,
    SET_SIZE_MAIN_WINDOW,
    SET_APP_NAME,
    DARK_MODE,
    SET_INTENT_OPEN_ACTIVITY,
    PUSH_CURRENT_ACTIVITY_STACK,
    CLEAR_PUSH_ACTIVITY_FLAG,
    CLEAR_INTENT_OPEN_ACTIVITY,
    SET_INTENT_DATA,
    CLEAR_INTENT_DATA,

    //// Clock
    SET_COLOR_ARROW_HOUR,
    SET_COLOR_ARROW_MINUTES,
    SET_COLOR_ARROW_SECONDS,
    SET_COLOR_CLOCK_BACKGROUND,
    SET_COLOR_CLOCK_TEXT,
    SET_CLOCK_TIME,
    RUN_CLOCK_TIME_DAEMON,
    STOP_CLOCK_TIME_DAEMON,

    //// AlarmClock
    ADD_ALARM_CLOCK,
    EDIT_ALARM_CLOCK,
    DELETE_ALARM_CLOCK,
    RUN_ALARM_CLOCK_DAEMON,
    STOP_ALARM_CLOCK_DAEMON,

    //// MainMenu
    SELECT_ITEM_MENU,

    //// Stopwatch
    START_STOPWATCH,
    STOP_STOPWATCH,
    CLEAR_STOPWATCH,
    RUN_STOPWATCH_DAEMON,
    STOP_STOPWATCH_DAEMON,

    //// Timer
    SET_TIMER,
    START_TIMER,
    STOP_TIMER,
    CLEAR_TIMER,
    RUN_TIMER_DAEMON,
    STOP_TIMER_DAEMON,
};

/*
 * Структура, которая описывает события в приложении
 * type - тип события
 * reducer - тип редюсера
 * data - неопределённый указатель на данные
 */
struct Action {
    ActionTypes type;
    ReducerTypes reducer;
    void *data;
};

#endif //CLOCK_ACTION_H
