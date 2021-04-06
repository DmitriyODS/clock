#ifndef CLOCK_ACTIONS_H
#define CLOCK_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие изменение цвета фона
Action setColorBackground(Color *color);

//// возврщает событие изменение цвета теста
Action setColorText(Color *color);

//// возврщает событие изменение цвета компонентов
Action setColorElements(Color *color);

//// возврщает событие изменение цвета выдиления
Action setColorAccent(Color *color);

//// возвращает событие изменение размера окна
Action setSizeMainWindow(Size *size);

#endif //CLOCK_ACTIONS_H
