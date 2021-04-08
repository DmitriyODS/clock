#include "actions.h"

Action selectItemMenu(void *intent_item) {
    return Action{
            ActionTypes::SELECT_ITEM_MENU,
            ReducerTypes::MAIN_MENU,
            intent_item
    };
}
