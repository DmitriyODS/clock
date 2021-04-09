#include "actions.h"

Action setColorBackground(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_BACKGROUND,
            ReducerTypes::APP,
            color
    };
}

Action setColorText(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_TEXT,
            ReducerTypes::APP,
            color
    };
}

Action setColorElements(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_ELEMENTS,
            ReducerTypes::APP,
            color
    };
}

Action setColorAccent(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_ACCENT,
            ReducerTypes::APP,
            color
    };
}

Action setSizeMainWindow(Size *size) {
    return Action{
            ActionTypes::SET_SIZE_MAIN_WINDOW,
            ReducerTypes::APP,
            size
    };
}

Action setAppName(string *app_name) {
    return Action{
            ActionTypes::SET_APP_NAME,
            ReducerTypes::APP,
            app_name
    };
}

Action darkMode(bool *is_dark) {
    return Action{
            ActionTypes::DARK_MODE,
            ReducerTypes::APP,
            is_dark
    };
}

Action setIntent(void *intent) {
    return Action{
            ActionTypes::SET_INTENT,
            ReducerTypes::APP,
            intent
    };
}

Action clearIntentOpenActivity() {
    return Action{
            ActionTypes::CLEAR_INTENT,
            ReducerTypes::APP
    };
}

Action setSelectComponent(void *component) {
    return Action{
            ActionTypes::SET_SELECT_COMPONENT,
            ReducerTypes::APP,
            component
    };
}

Action setExit() {
    return Action{
            ActionTypes::SET_EXIT,
            ReducerTypes::APP
    };
}
