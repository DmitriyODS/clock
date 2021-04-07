#ifndef MAIN_MENU_REDUCER_H
#define MAIN_MENU_REDUCER_H

#include <Action.h>
#include <MainMenu/State/State.h>

//// reducer для объекта main menu
MainMenuState mainMenuReducer(
        MainMenuState state = MainMenuState{},
        Action action = Action{ActionTypes::INITIAL_STATE}
);

#endif //MAIN_MENU_REDUCER_H
