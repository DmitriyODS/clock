#ifndef TIMER_REDUCER_H
#define TIMER_REDUCER_H

#include <Action.h>
#include <Timer/State/State.h>

//// reducer для объекта timer
TimerState timerReducer(
        TimerState state = TimerState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //TIMER_REDUCER_H
