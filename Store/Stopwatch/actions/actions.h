#ifndef STOPWATCH_ACTIONS_H
#define STOPWATCH_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие запуска секундомера
Action startStopwatch();

//// возврщает событие остановки секундомера
Action stopStopwatch();

//// возврщает событие очистки секундомера
Action clearStopwatch();

//// возвращает событие запуска демона секундомера
Action runStopwatchDaemon();

//// возвращает событие остановки демона секундомера
Action stopStopwatchDaemon();

#endif //STOPWATCH_ACTIONS_H
