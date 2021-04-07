#include "MainActivity.h"

void MainActivity::render() {

}

void MainActivity::start() {

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
