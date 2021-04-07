#include "actions.h"

Action startStopwatch() {
    return Action{
            ActionTypes::START_STOPWATCH,
            ReducerTypes::STOPWATCH
    };
}

Action stopStopwatch() {
    return Action{
            ActionTypes::STOP_STOPWATCH,
            ReducerTypes::STOPWATCH
    };
}

Action clearStopwatch() {
    return Action{
            ActionTypes::CLEAR_STOPWATCH,
            ReducerTypes::STOPWATCH
    };
}

Action runStopwatchDaemon() {
    return Action{
            ActionTypes::RUN_STOPWATCH_DAEMON,
            ReducerTypes::STOPWATCH
    };
}

Action stopStopwatchDaemon() {
    return Action{
            ActionTypes::STOP_STOPWATCH_DAEMON,
            ReducerTypes::STOPWATCH
    };
}
