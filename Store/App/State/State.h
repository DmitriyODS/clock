#ifndef CLOCK_STATE_H
#define CLOCK_STATE_H

#include <globalTypes.h>

// здесь мы описываем все поля,
// которые являются состоянием
// для текущей логической единицы
struct AppState {
    ColorApp color_app{};
    Size size_main_window{};
};

#endif //CLOCK_STATE_H
