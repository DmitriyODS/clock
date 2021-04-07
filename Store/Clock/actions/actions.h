#ifndef CLOCK_ACTIONS_H
#define CLOCK_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие изменение цвета часовой стрелки
Action setColorArrowHour(Color *color);

//// возврщает событие изменение цвета минутной стрелки
Action setColorArrowMinutes(Color *color);

//// возврщает событие изменение цвета секундной стрелки
Action setColorArrowSeconds(Color *color);

//// возврщает событие изменение цвета фона часов
Action setColorClockBackground(Color *color);

//// возвращает событие изменения цвета фона текста на часах
Action setColorClockText(Color *color);

//// возвращает событие изменения времени
Action setCurrentTime(ClockTime *clock_time);

//// возвращает событие запуска демона времени
Action runClockTimeDaemon();

//// возвращает событие остановки демона времени
Action stopClockTimeDaemon();

#endif //CLOCK_ACTIONS_H
