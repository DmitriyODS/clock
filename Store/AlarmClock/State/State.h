#ifndef ALARM_CLOCK_STATE_H
#define ALARM_CLOCK_STATE_H

#include <globalTypes.h>

/*
 * Описываем все состояния нашего объекта alarm clock
 */
struct AlarmClockState {
    AlarmClocks alarm_clocks{};
    bool run_alarm_clock_daemon{};
};

#endif //ALARM_CLOCK_STATE_H
