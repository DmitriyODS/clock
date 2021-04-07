#ifndef STOPWATCH_STATE_H
#define STOPWATCH_STATE_H

#include <globalTypes.h>

/*
 * Описываем все состояния нашего объекта stopwatch
 */
struct StopwatchState {
    ClockTime current_time{};
    bool enabled{};
};

#endif //STOPWATCH_STATE_H
