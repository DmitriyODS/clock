#ifndef MAIN_MENU_ACTIONS_H
#define MAIN_MENU_ACTIONS_H

#include <Action.h>
#include <globalTypes.h>

// прописываем функции, которые будут
// создавать действия для нашего dispatch

//// возврщает событие выбор пункта меню
Action selectItemMenu(ItemMenuId *item_menu_id);


#endif //MAIN_MENU_ACTIONS_H
