#include "reducer.h"

AppState appReducer(AppState app_state, Action action) {
    switch (action.type) {
        case ActionTypes::SET_COLOR_BACKGROUND:
            return app_state;
        case ActionTypes::SET_COLOR_TEXT:
            return app_state;
        case ActionTypes::SET_COLOR_ELEMENTS:
            return app_state;
        case ActionTypes::SET_COLOR_ACCENT:
            return app_state;
        case ActionTypes::SET_SIZE_MAIN_WINDOW:
            return app_state;
        default:
            return app_state;
    }
}
