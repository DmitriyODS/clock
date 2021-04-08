#include "LoadingActivity.h"

LoadingActivity::LoadingActivity()
        : BaseActivity(
        Activity::LOADING,
        "Loading",
        VideoMode(800, 500),
        StyleWindow::None
) {}

void LoadingActivity::start() {
    Thread postpone_thread(postponeEventDaemon, 3, [this]() {
        this->m_is_running = false;
    });

    postpone_thread.launch();

    BaseActivity::start();
}
