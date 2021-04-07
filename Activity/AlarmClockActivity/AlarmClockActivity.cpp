#include "AlarmClockActivity.h"

void AlarmClockActivity::render() {

}

void AlarmClockActivity::start() {

}

void AlarmClockActivity::_init() {
    m_store = Store::getStore();
}

AlarmClockActivity::AlarmClockActivity() {
    _init();
}

AlarmClockActivity *AlarmClockActivity::createActivity() {
    static auto *alarmClockActivity = new AlarmClockActivity();

    return alarmClockActivity;
}
