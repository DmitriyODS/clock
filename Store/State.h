#ifndef CLOCK_STATE_H
#define CLOCK_STATE_H

#include <App/State/State.h>

/*
 * Глобальный объект состояния
 * который соединяет в себе все
 * состояния приложения
 */
struct State {
    AppState app_state{};
};

#endif //CLOCK_STATE_H
