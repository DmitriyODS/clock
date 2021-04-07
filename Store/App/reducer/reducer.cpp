#include "reducer.h"

AppState appReducer(AppState state, Action action) {
    switch (action.type) {
        case ActionTypes::SET_COLOR_BACKGROUND: {
            state.color_app.background = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_TEXT: {
            state.color_app.text = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_ELEMENTS: {
            state.color_app.elements = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_ACCENT: {
            state.color_app.accent = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_SIZE_MAIN_WINDOW: {
            state.size_main_window = *static_cast<Size *>(action.data);
            return state;
        }
        case ActionTypes::SET_APP_NAME: {
            state.app_name = *static_cast<string *>(action.data);
            return state;
        }
        case ActionTypes::DARK_MODE: {
            state.dark_mode = *static_cast<bool *>(action.data);
            return state;
        }
        case ActionTypes::SET_INTENT_OPEN_ACTIVITY: {
            state.intent_open_activity = action.data;
            return state;
        }
        case ActionTypes::CLEAR_INTENT_OPEN_ACTIVITY: {
            state.intent_open_activity = nullptr;
            return state;
        }
        case ActionTypes::SET_INTENT_DATA: {
            state.intent_data = action.data;
            return state;
        }
        case ActionTypes::CLEAR_INTENT_DATA: {
            state.intent_data = nullptr;
            return state;
        }
        case ActionTypes::PUSH_CURRENT_ACTIVITY_STACK: {
            state.intent_push_activity = true;
            return state;
        }
        case ActionTypes::CLEAR_PUSH_ACTIVITY_FLAG: {
            state.intent_push_activity = false;
            return state;
        }
        default: {
            return state;
        }
    }
}
