#include "LoadingActivity.h"

LoadingActivity::LoadingActivity()
        : BaseActivity(
        Activity::LOADING,
        "Loading",
        VideoMode(800, 500),
        StyleWindow::None
) {}
