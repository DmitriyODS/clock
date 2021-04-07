#include "reducer.h"

MainMenuState mainMenuReducer(MainMenuState state, Action action) {
    switch (action.type) {
        case ActionTypes::SELECT_ITEM_MENU: {
            state.current_item = *static_cast<ItemMenuId *>(action.data);
            return state;
        }
        default: {
            return state;
        }
    }
}
