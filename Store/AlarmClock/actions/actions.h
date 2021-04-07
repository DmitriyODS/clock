#ifndef ALARM_CLOCK_ACTIONS_H
#define ALARM_CLOCK_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие добавление нового будильника
Action addAlarmClock(AlarmClock *alarm_clock);

//// возврщает событие изменение будильника
Action editAlarmClockById(AlarmClock *alarm_clock);

//// возврщает событие удаление будильника
Action deleteAlarmClockById(AlarmClock *alarm_clock);

#endif //ALARM_CLOCK_ACTIONS_H
