#ifndef TIMER_STATE_H
#define TIMER_STATE_H

#include <globalTypes.h>

/*
 * Описываем все состояния нашего объекта timer
 */
struct TimerState {
    ClockTime end_time{};
    bool enabled{};
    bool run_timer_state_daemon{};
};

#endif //TIMER_STATE_H
