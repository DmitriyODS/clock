#ifndef APP_REDUCER_H
#define APP_REDUCER_H

#include <Action.h>
#include <App/State/State.h>

//// reducer для объекта app
AppState appReducer(
        AppState state = AppState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //APP_REDUCER_H
