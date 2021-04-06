#ifndef CLOCK_REDUCER_H
#define CLOCK_REDUCER_H

#include <Action.h>
#include <App/State/State.h>

//// reducer для объекта app
AppState appReducer(AppState app_state, Action action);

#endif //CLOCK_REDUCER_H
