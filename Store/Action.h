#ifndef CLOCK_ACTION_H
#define CLOCK_ACTION_H

/*
 * Храним типы редюсеров
 * нашего приложения
 */
enum class ReducerTypes {
    APP,
    CLOCK,
    CLOCK_ALARM,
    MAIN_MENU,
    STOPWATCH,
    TIMER
};

/*
 * Храним типы событий
 * нашего приложения
 */
enum class ActionTypes {
    SET_COLOR_BACKGROUND,
    SET_COLOR_TEXT,
    SET_COLOR_ELEMENTS,
    SET_COLOR_ACCENT,

    SET_SIZE_MAIN_WINDOW,
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
