#include "AlarmClockActivity.h"

AlarmClockActivity::AlarmClockActivity()
        : BaseActivity(
        Activity::ALARM_CLOCK,
        "Alarm clock",
        VideoMode(800, 500),
        StyleWindow::Default
) {}
