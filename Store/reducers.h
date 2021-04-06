#ifndef CLOCK_REDUCERS_H
#define CLOCK_REDUCERS_H

#include <Action.h>
#include <State.h>
#include <App/reducer/reducer.h>


//// функция обработки всех редюсеров нашего приложения
//// на вход получает state и action
//// возвращает новый state
State reducers(State state, Action action);

#endif //CLOCK_REDUCERS_H
