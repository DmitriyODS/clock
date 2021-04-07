#include "daemons.h"

sf::Mutex GlobalMutex{};

void timeClockDaemon() {
    GlobalMutex.lock();
    std::clog << "Time clock daemon start" << std::endl;
    GlobalMutex.unlock();

    Store *store = Store::getStore();

    auto *clockTime = new ClockTime{};

    while (store->getState().clock_state.run_clock_time_daemon) {
        *clockTime = time(nullptr);
        store->dispatch(setCurrentTime(clockTime));
    }

    delete clockTime;

    GlobalMutex.lock();
    std::clog << "Time clock daemon stop" << std::endl;
    GlobalMutex.unlock();
}

void alarmClockDaemon() {
    GlobalMutex.lock();
    std::clog << "Alarm clock daemon start" << std::endl;
    GlobalMutex.unlock();

    Store *store = Store::getStore();

    while (store->getState().alarm_clock_state.run_alarm_clock_daemon) {
    }

    GlobalMutex.lock();
    std::clog << "Alarm clock daemon stop" << std::endl;
    GlobalMutex.unlock();
}

void timerDaemon() {
    GlobalMutex.lock();
    std::clog << "Timer daemon start" << std::endl;
    GlobalMutex.unlock();

    Store *store = Store::getStore();

    while (store->getState().timer_state.run_timer_state_daemon) {
    }

    GlobalMutex.lock();
    std::clog << "Timer daemon stop" << std::endl;
    GlobalMutex.unlock();
}

void stopwatchDaemon() {
    GlobalMutex.lock();
    std::clog << "Stopwatch daemon start" << std::endl;
    GlobalMutex.unlock();

    Store *store = Store::getStore();

    while (store->getState().stopwatch_state.run_stopwatch_daemon) {
    }

    GlobalMutex.lock();
    std::clog << "Stopwatch daemon stop" << std::endl;
    GlobalMutex.unlock();
}

void postponeEventDaemon(float duration, const PostponeFunction &callback) {
    GlobalMutex.lock();
    std::clog << "Postpone event daemon start" << std::endl;
    GlobalMutex.unlock();

    sleep(sf::seconds(duration));
    callback();

    GlobalMutex.lock();
    std::clog << "Postpone event daemon stop" << std::endl;
    GlobalMutex.unlock();
}
