#include "reducer.h"

StopwatchState stopwatchReducer(StopwatchState state, Action action) {
    switch (action.type) {
        case ActionTypes::START_STOPWATCH: {
            state.enabled = true;
            return state;
        }
        case ActionTypes::STOP_STOPWATCH: {
            state.enabled = false;
            return state;
        }
        case ActionTypes::CLEAR_STOPWATCH: {
            state.enabled = false;
            state.current_time = ClockTime{};
            return state;
        }
        case ActionTypes::RUN_STOPWATCH_DAEMON: {
            state.run_stopwatch_daemon = true;
            return state;
        }
        case ActionTypes::STOP_STOPWATCH_DAEMON: {
            state.run_stopwatch_daemon = false;
            return state;
        }
        default: {
            return state;
        }
    }
}
