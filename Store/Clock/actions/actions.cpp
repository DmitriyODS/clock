#include "actions.h"

Action setColorArrowHour(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_ARROW_HOUR,
            ReducerTypes::CLOCK,
            color
    };
}

Action setColorArrowMinutes(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_ARROW_MINUTES,
            ReducerTypes::CLOCK,
            color
    };
}

Action setColorArrowSeconds(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_ARROW_SECONDS,
            ReducerTypes::CLOCK,
            color
    };
}

Action setColorClockBackground(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_CLOCK_BACKGROUND,
            ReducerTypes::CLOCK,
            color
    };
}

Action setColorClockText(Color *color) {
    return Action{
            ActionTypes::SET_COLOR_CLOCK_TEXT,
            ReducerTypes::CLOCK,
            color
    };
}

Action setCurrentTime(ClockTime *clock_time) {
    return Action{
            ActionTypes::SET_CLOCK_TIME,
            ReducerTypes::CLOCK,
            clock_time
    };
}

Action runClockTimeDaemon() {
    return Action{
            ActionTypes::RUN_CLOCK_TIME_DAEMON,
            ReducerTypes::CLOCK
    };
}

Action stopClockTimeDaemon() {
    return Action{
            ActionTypes::STOP_CLOCK_TIME_DAEMON,
            ReducerTypes::CLOCK
    };
}
