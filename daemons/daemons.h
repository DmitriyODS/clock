#ifndef CLOCK_DAEMONS_H
#define CLOCK_DAEMONS_H

#include <Store.h>
#include <ctime>
#include <SFML/System.hpp>

/*
 * Здесь живут демоны, которые работают с фоновыми процессами
 * не мешайте им :)
 */

//// демон обновляет время
void timeClockDaemon();

//// демон работает будильником
void alarmClockDaemon();

//// демон отсчитывает время
void timerDaemon();

//// демон засекает время
void stopwatchDaemon();

#endif //CLOCK_DAEMONS_H
