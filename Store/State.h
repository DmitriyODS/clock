#ifndef CLOCK_STATE_H
#define CLOCK_STATE_H

#include <App/State/State.h>
#include <AlarmClock/State/State.h>
#include <Clock/State/State.h>
#include <MainMenu/State/State.h>
#include <Stopwatch/State/State.h>
#include <Timer/State/State.h>

/*
 * Глобальный объект состояния
 * который соединяет в себе все
 * состояния приложения
 */
struct State {
    AppState app_state{};
    AlarmClockState alarm_clock_state{};
    ClockState clock_state{};
    MainMenuState main_menu_state{};
    StopwatchState stopwatch_state{};
    TimerState timer_state{};
};

#endif //CLOCK_STATE_H
