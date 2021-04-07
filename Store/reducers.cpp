#include "reducers.h"

State reducers(State state, Action action) {
    switch (action.reducer) {
        case ReducerTypes::APP:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::CLOCK:
            state.clock_state = clockReducer(state.clock_state, action);
            return state;
        case ReducerTypes::ALARM_CLOCK:
            state.alarm_clock_state = alarmClockReducer(state.alarm_clock_state, action);
            return state;
        case ReducerTypes::MAIN_MENU:
            state.main_menu_state = mainMenuReducer(state.main_menu_state, action);
            return state;
        case ReducerTypes::STOPWATCH:
            state.stopwatch_state = stopwatchReducer(state.stopwatch_state, action);
            return state;
        case ReducerTypes::TIMER:
            state.timer_state = timerReducer(state.timer_state, action);
            return state;
        case ReducerTypes::ALL:
            state.app_state = appReducer();
            state.clock_state = clockReducer();
            state.alarm_clock_state = alarmClockReducer();
            state.main_menu_state = mainMenuReducer();
            state.timer_state = timerReducer();
            state.stopwatch_state = stopwatchReducer();
            return state;
        default:
            return state;
    }
}
