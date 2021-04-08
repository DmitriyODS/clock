#include "MainActivity.h"

void MainActivity::_init() {
    m_is_runnning = true;

    m_window = new RenderWindow(
            VideoMode::getDesktopMode(),
            "Clock-Master",
            StyleWindow::Fullscreen
    );

    m_window->setVerticalSyncEnabled(true);
}

void MainActivity::_reinit() {
    m_window->create(
            sf::VideoMode::getFullscreenModes()[1],
            "Clock-Master"
    );
}

void MainActivity::start(MapActivity *map_activity) {
    // если ещё нет, то иницитим окно
    if (!m_window) {
        _init();
    } else {
        _reinit();
    }

    // пробуем запустить отрисовку в отдельном потоке
    // для оптимизации производительности
    m_window->setActive(false);

    Thread render_thread(&MainActivity::render, this);
    render_thread.launch();

    while (m_window->isOpen()) {

        Event event{};

        while (m_window->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed: {
                    m_is_runnning = false;
                    break;
                }
            }
        }

        // TODO: подумать, можно ли сделать как - то красиво
        if (!m_is_runnning) {
            m_window->close();
        }
    }
}

void MainActivity::render() {
    m_window->setActive(true);

    while (m_is_runnning) {
        m_window->clear(Color::White);

        for (auto item : m_components) {
            item->render(m_window);
        }

        m_window->display();
    }
}

MainActivity::MainActivity() : m_store(Store::getStore()) {}

MainActivity *MainActivity::createActivity() {
    static auto *mainActivity = new MainActivity();

    return mainActivity;
}
