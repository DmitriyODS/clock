#ifndef APP_ACTIONS_H
#define APP_ACTIONS_H

#include <Action.h>
#include <string>
#include <globalTypes.h>

using std::string;

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

//// возвращает событие установки названия приложения
Action setAppName(string *app_name);

//// возвращает событие переключателя тёмной темы
Action darkMode(bool *is_dark);

//// возвращает событие открытия новой активности
Action setIntentOpenActivity(IDActivity *idActivity);

//// возвращает событие очистка открытия новой активности
Action clearIntentOpenActivity();

//// возвращает событие установка данных
Action setIntentData(void *data);

//// возвращает событие очистки данных
Action clearIntentData();

//// возвращает событие выставить флаг помещения в стек
Action pushStackActivity();

//// возвращает событие снять флаг помещения в стек
Action clearPushStackActivity();

#endif //APP_ACTIONS_H
