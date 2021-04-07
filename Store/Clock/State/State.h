#ifndef CLOCK_TIME_STATE_H
#define CLOCK_TIME_STATE_H

#include <globalTypes.h>

/*
 * Описываем все состояния нашего объекта clock
 */
struct ClockState {
    ColorClock color_clock{};
    ClockTime current_time{};
};

#endif //CLOCK_TIME_STATE_H
