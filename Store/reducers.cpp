#include "reducers.h"

State reducers(State state, Action action) {
    switch (action.reducer) {
        case ReducerTypes::APP:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::CLOCK:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::CLOCK_ALARM:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::MAIN_MENU:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::STOPWATCH:
            state.app_state = appReducer(state.app_state, action);
            return state;
        case ReducerTypes::TIMER:
            state.app_state = appReducer(state.app_state, action);
            return state;
    }
}
