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
        default: {
            return state;
        }
    }
}
