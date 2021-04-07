#include "reducer.h"

TimerState timerReducer(TimerState state, Action action) {
    switch (action.type) {
        case ActionTypes::SET_TIMER: {
            state.end_time = *static_cast<ClockTime *>(action.data);
            return state;
        }
        case ActionTypes::START_TIMER: {
            state.enabled = true;
            return state;
        }
        case ActionTypes::STOP_TIMER: {
            state.enabled = false;
            return state;
        }
        case ActionTypes::CLEAR_TIMER: {
            state.enabled = false;
            state.end_time = ClockTime{};
            return state;
        }
        case ActionTypes::RUN_TIMER_DAEMON: {
            state.run_timer_state_daemon = true;
            return state;
        }
        case ActionTypes::STOP_TIMER_DAEMON: {
            state.run_timer_state_daemon = false;
            return state;
        }
        default: {
            return state;
        }
    }
}
