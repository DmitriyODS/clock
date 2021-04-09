#include "LoadingActivity.h"

LoadingActivity::LoadingActivity()
        : BaseActivity(
        Activity::LOADING,
        "Loading",
        VideoMode(800, 500),
        StyleWindow::None
) {}

void LoadingActivity::start() {
    Thread postpone_thread(std::bind(&postponeEventDaemon, 3, [this]() {
        this->m_is_running = false;
    }));

    postpone_thread.launch();

    BaseActivity::start();
}

void LoadingActivity::_createIntent() {
    BaseActivity::_createIntent();

    auto *intent = new Intent{
            Activity::MAIN
    };

    m_store->dispatch(setIntent(intent));
}

void LoadingActivity::_initComponents() {
    BaseActivity::_initComponents();

    auto *loadingScreen = new LoadingScreen(Vector2f(), Vector2f());

    m_components.push_back(
            loadingScreen
    );
}
