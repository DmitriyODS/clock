#include <iostream>
#include <Store.h>
#include <reducers.h>
#include <string>
#include <App/actions/actions.h>

#include <SFML/Graphics.hpp>


int main() {
    sf::Color();

    Store *store = Store::createStore(reducers);

    Subscriber subscrabe = [store]() {
        std::cout << store->getState().app_state.app_name << std::endl;
    };

    string str = "Clock-Master";

    store->subscribe(subscrabe);

    store->dispatch(setAppName(&str));
    store->dispatch(setAppName(&str));
    store->dispatch(setAppName(&str));
    store->dispatch(setAppName(&str));
    store->dispatch(setAppName(&str));

    return 0;
}
