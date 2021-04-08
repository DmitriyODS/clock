#ifndef APP_STATE_H
#define APP_STATE_H

#include <globalTypes.h>
#include <string>

using std::string;

/*
 * Описываем все состояния нашего объекта app
 */
struct AppState {
    ColorApp color_app{};
    Size size_main_window{};
    string app_name{};
    bool dark_mode{};
    void *intent{};
    void *select_component{};
};

#endif //APP_STATE_H
