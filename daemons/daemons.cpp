#include "daemons.h"

sf::Mutex GlobalMutex{};

void timeClockDaemon() {
    Store *store = Store::getStore();

    while (store->getState().clock_state.run_clock_time_daemon) {
        sf::Lock lock(GlobalMutex);
    }

}

void alarmClockDaemon() {
    Store *store = Store::getStore();

    while (store->getState().alarm_clock_state.run_alarm_clock_daemon) {
        sf::Lock lock(GlobalMutex);
    }
}

void timerDaemon() {
    Store *store = Store::getStore();

    while (store->getState().timer_state.run_timer_state_daemon) {
        sf::Lock lock(GlobalMutex);
    }
}

void stopwatchDaemon() {
    Store *store = Store::getStore();

    while (store->getState().stopwatch_state.run_stopwatch_daemon) {
        sf::Lock lock(GlobalMutex);
    }
}
