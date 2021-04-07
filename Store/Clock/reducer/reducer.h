#ifndef CLOCK_REDUCER_H
#define CLOCK_REDUCER_H

#include <Action.h>
#include <Clock/State/State.h>

//// reducer для объекта clock
ClockState clockReducer(
        ClockState state = ClockState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //CLOCK_REDUCER_H
