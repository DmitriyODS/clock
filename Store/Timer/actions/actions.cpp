#include "actions.h"

Action setTimer(ClockTime *clock_time) {
    return Action{
            ActionTypes::SET_TIMER,
            ReducerTypes::TIMER,
            clock_time
    };
}

Action startTimer() {
    return Action{
            ActionTypes::START_TIMER,
            ReducerTypes::TIMER
    };
}

Action stopTimer() {
    return Action{
            ActionTypes::STOP_TIMER,
            ReducerTypes::TIMER
    };
}

Action clearTimer() {
    return Action{
            ActionTypes::CLEAR_TIMER,
            ReducerTypes::TIMER
    };
}

Action runTimerDaemon() {
    return Action{
            ActionTypes::RUN_TIMER_DAEMON,
            ReducerTypes::TIMER
    };
}

Action stopTimerDaemon() {
    return Action{
            ActionTypes::STOP_TIMER_DAEMON,
            ReducerTypes::TIMER
    };
}
