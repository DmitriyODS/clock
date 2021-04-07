#ifndef TIMER_ACTIONS_H
#define TIMER_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие установки таймера
Action setTimer(ClockTime *clock_time);

//// возврщает событие запуска таймера
Action startTimer();

//// возврщает событие остановки таймера
Action stopTimer();

//// возврщает событие сброса таймера
Action clearTimer();

//// возвращает событие запуска демона таймера
Action runTimerDaemon();

//// возвращает событие остановки демона таймера
Action stopTimerDaemon();

#endif //TIMER_ACTIONS_H
