#include "reducer.h"

MainMenuState mainMenuReducer(MainMenuState state, Action action) {
    switch (action.type) {
        case ActionTypes::SELECT_ITEM_MENU: {
            state.intent_item = action.data;
            return state;
        }
        default: {
            return state;
        }
    }
}
