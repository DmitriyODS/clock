#include <iostream>
#include <Store.h>
#include <reducers.h>
#include <string>
#include <App/actions/actions.h>

#include <SFML/Graphics.hpp>

int main() {
    sf::Color();

    Store *store = Store::createStore(reducers);

    string str = "Clock-Master";

    store->dispatch(setAppName(&str));

    std::cout << store->getState().app_state.app_name << std::endl;
    return 0;
}
