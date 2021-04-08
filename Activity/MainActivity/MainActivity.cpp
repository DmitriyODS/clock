#include "MainActivity.h"

void MainActivity::_init() {
    m_is_running = true;

    m_window = new RenderWindow(
            sf::VideoMode::getDesktopMode(),
            "Clock-Master"
    );

    m_window->setVerticalSyncEnabled(true);
}

void MainActivity::render() {

}

void MainActivity::start(MapActivity *map_activity) {
    // если ещё нет, то иницитим окно
    if (!m_window) {
        _init();
    }
}

MainActivity::MainActivity() : m_store(Store::getStore()) {}

MainActivity *MainActivity::createActivity() {
    static auto *mainActivity = new MainActivity();

    return mainActivity;
}
