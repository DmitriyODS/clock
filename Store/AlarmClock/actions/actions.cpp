#include "actions.h"

Action addAlarmClock(AlarmClock *alarm_clock) {
    return Action{
            ActionTypes::ADD_ALARM_CLOCK,
            ReducerTypes::ALARM_CLOCK,
            alarm_clock
    };
}

Action editAlarmClockById(AlarmClock *alarm_clock) {
    return Action{
            ActionTypes::EDIT_ALARM_CLOCK,
            ReducerTypes::ALARM_CLOCK,
            alarm_clock
    };
}

Action deleteAlarmClockById(AlarmClock *alarm_clock) {
    return Action{
            ActionTypes::DELETE_ALARM_CLOCK,
            ReducerTypes::ALARM_CLOCK,
            alarm_clock
    };
}

Action runAlarmClockDaemon() {
    return Action{
            ActionTypes::RUN_ALARM_CLOCK_DAEMON,
            ReducerTypes::ALARM_CLOCK
    };
}

Action stopAlarmClockDaemon() {
    return Action{
            ActionTypes::STOP_ALARM_CLOCK_DAEMON,
            ReducerTypes::ALARM_CLOCK
    };
}
