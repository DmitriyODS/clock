#include "MainActivity.h"

MainActivity::MainActivity()
        : BaseActivity(
        Activity::MAIN,
        "Clock Master",
        VideoMode::getDesktopMode(),
        StyleWindow::Fullscreen
) {}
