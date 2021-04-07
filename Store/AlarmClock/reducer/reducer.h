#ifndef ALARM_CLOCK_REDUCER_H
#define ALARM_CLOCK_REDUCER_H

#include <Action.h>
#include <AlarmClock/State/State.h>

//// reducer для объекта alarm clock
AlarmClockState alarmClockReducer(
        AlarmClockState state = AlarmClockState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //ALARM_CLOCK_REDUCER_H
