#ifndef CLOCK_REDUCERS_H
#define CLOCK_REDUCERS_H

#include <Action.h>
#include <State.h>
#include <App/reducer/reducer.h>
#include <Clock/reducer/reducer.h>
#include <Stopwatch/reducer/reducer.h>
#include <Timer/reducer/reducer.h>
#include <MainMenu/reducer/reducer.h>
#include <AlarmClock/reducer/reducer.h>
#include <functional>


//// функция обработки всех редюсеров нашего приложения
//// на вход получает state и action
//// возвращает новый state
State reducers(
        State state = State{},
        Action action = Action{ActionTypes::INITIAL_STATE, ReducerTypes::ALL}
);

//// тип функции - редюсер
using Reducer = std::function<State(State, Action)>;

#endif //CLOCK_REDUCERS_H
