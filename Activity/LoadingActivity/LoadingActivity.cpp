#include "LoadingActivity.h"

void LoadingActivity::_init() {
    m_is_runnning = true;

    m_window = new RenderWindow(
            VideoMode(800, 500),
            "LoadingScreen",
            StyleWindow::None
    );

    m_window->setVerticalSyncEnabled(true);

    m_components.push_back(
            new LoadingScreen()
    );
}

void LoadingActivity::start(MapActivity *map_activity) {
    // если окно не создано, создаём его
    if (!m_window) {
        _init();
    }

    // запуск демона отложенного события
    // он закроет окно после 5 секунд
    Thread postpone_event_daemon(
            std::bind(
                    &postponeEventDaemon,
                    3,
                    [this]() { m_is_runnning = false; }
            )
    );
    postpone_event_daemon.launch();

    // пробуем запустить отрисовку в отдельном потоке
    // для оптимизации производительности
    m_window->setActive(false);

    Thread render_thread(&LoadingActivity::render, this);
    render_thread.launch();

    while (m_window->isOpen() && m_is_runnning) {

        Event event{};

        while (m_window->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed: {
                    m_window->close();
                    break;
                }
            }
        }
    }

    m_store->dispatch(setIntentOpenActivity(map_activity->at(IDActivity::MAIN)));
}

void LoadingActivity::render() {
    m_window->setActive(true);

    while (m_window->isOpen() && m_is_runnning) {
        m_window->clear(Color::White);

        for (auto item : m_components) {
            item->render(m_window);
        }

        m_window->display();
    }
}

LoadingActivity::LoadingActivity()
        : m_store(Store::getStore()) {
}

LoadingActivity *LoadingActivity::createActivity() {
    static auto *loadingActivity = new LoadingActivity();

    return loadingActivity;
}
