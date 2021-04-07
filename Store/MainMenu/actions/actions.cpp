#include "actions.h"

Action selectItemMenu(ItemMenuId *item_menu_id) {
    return Action{
            ActionTypes::SELECT_ITEM_MENU,
            ReducerTypes::MAIN_MENU,
            item_menu_id
    };
}
