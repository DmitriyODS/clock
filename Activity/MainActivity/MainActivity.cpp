#include "MainActivity.h"

void MainActivity::render() {

}

void MainActivity::start(MapActivity *map_activity) {
    std::cout << "All good!" << std::endl;
}

void MainActivity::_init() {

}

MainActivity::MainActivity() {
    _init();
}

MainActivity *MainActivity::createActivity() {
    static auto *mainActivity = new MainActivity();

    return mainActivity;
}
