#include "reducer.h"

ClockState clockReducer(ClockState state, Action action) {
    switch (action.type) {
        case ActionTypes::SET_COLOR_ARROW_HOUR: {
            state.color_clock.hour = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_ARROW_MINUTES: {
            state.color_clock.minutes = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_ARROW_SECONDS: {
            state.color_clock.seconds = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_CLOCK_BACKGROUND: {
            state.color_clock.background = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_COLOR_CLOCK_TEXT: {
            state.color_clock.text = *static_cast<Color *>(action.data);
            return state;
        }
        case ActionTypes::SET_CLOCK_TIME: {
            state.current_time = *static_cast<ClockTime *>(action.data);
            return state;
        }
        case ActionTypes::RUN_CLOCK_TIME_DAEMON: {
            state.run_clock_time_daemon = true;
            return state;
        }
        case ActionTypes::STOP_CLOCK_TIME_DAEMON: {
            state.run_clock_time_daemon = false;
            return state;
        }
        default: {
            return state;
        }
    }
}
