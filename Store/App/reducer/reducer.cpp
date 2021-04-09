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
        case ActionTypes::SET_INTENT: {
            state.intent = action.data;
            return state;
        }
        case ActionTypes::CLEAR_INTENT: {
            state.intent = nullptr;
            return state;
        }
        case ActionTypes::SET_SELECT_COMPONENT: {
            state.select_component = action.data;
            return state;
        }
        case ActionTypes::SET_EXIT: {
            state.m_exit = true;
            return state;
        }
        default: {
            return state;
        }
    }
}
