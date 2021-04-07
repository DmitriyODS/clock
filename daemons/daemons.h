#ifndef CLOCK_DAEMONS_H
#define CLOCK_DAEMONS_H

#include <Store.h>
#include <ctime>
#include <SFML/System.hpp>
#include <iostream>
#include <functional>
#include <Clock/actions/actions.h>

using sf::sleep;

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


//// тип функции отложенного вызова
using PostponeFunction = std::function<void()>;

//// демон отложенного события
void postponeEventDaemon(float duration, const PostponeFunction& callback);

#endif //CLOCK_DAEMONS_H
