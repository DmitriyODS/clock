#ifndef STOPWATCH_REDUCER_H
#define STOPWATCH_REDUCER_H

#include <Action.h>
#include <Stopwatch/State/State.h>

//// reducer для объекта stopwatch
StopwatchState stopwatchReducer(
        StopwatchState state = StopwatchState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //STOPWATCH_REDUCER_H
