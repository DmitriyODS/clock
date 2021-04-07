#include "reducer.h"

AlarmClockState alarmClockReducer(AlarmClockState state, Action action) {
    switch (action.type) {
        case ActionTypes::ADD_ALARM_CLOCK: {
            state.alarm_clocks.push_back(
                    new AlarmClock(*static_cast<AlarmClock *>(action.data))
            );
            return state;
        }
        case ActionTypes::EDIT_ALARM_CLOCK: {
            auto *alarmClock = static_cast<AlarmClock *>(action.data);
            *state.alarm_clocks.at(alarmClock->position) = *alarmClock;
            return state;
        }
        case ActionTypes::DELETE_ALARM_CLOCK: {
            auto *alarmClock = static_cast<AlarmClock *>(action.data);
            delete state.alarm_clocks.at(alarmClock->position);
            state.alarm_clocks.erase(state.alarm_clocks.begin() + alarmClock->position);
            return state;
        }
        case ActionTypes::RUN_ALARM_CLOCK_DAEMON: {
            state.run_alarm_clock_daemon = true;
            return state;
        }
        case ActionTypes::STOP_ALARM_CLOCK_DAEMON: {
            state.run_alarm_clock_daemon = false;
            return state;
        }
        default: {
            return state;
        }
    }
}
