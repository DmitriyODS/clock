#include "App.h"

void App::_init() {
    m_opening = Activity::LOADING;

    _createNewActivity();
}

App::App()
        : m_store(Store::createStore(reducers)) {
    _init();
}

App &App::createApp() {
    static App app{};

    return app;
}

int App::start() {
    // запускаем демона времени
    Thread clock_time_daemon(timeClockDaemon);
    m_store->dispatch(runClockTimeDaemon());
    clock_time_daemon.launch();

    // запускаем демона будильников
    Thread alarm_clock_daemon(alarmClockDaemon);
    m_store->dispatch(runAlarmClockDaemon());
    alarm_clock_daemon.launch();

    m_is_running = true;

    while (m_is_running) {
        if (m_current_activity) {
            m_current_activity->start();
        } else {
            std::cerr << "The current screen is not set!" << std::endl;
            m_is_running = false;
            continue;
        }

        _activityTransaction();
    }

    // останавливаем демона будильников
    m_store->dispatch(stopAlarmClockDaemon());

    // останавливаем демона часов
    m_store->dispatch(stopClockTimeDaemon());

    return 0;
}

bool App::_pushStackCurrentScreen() {
    // если имеется текущий скрин
    // то добавляем указатель на него
    // в стэк
    if (m_current_activity) {
        m_stack_activity.push(m_current_activity->getId());
        return true;
    }

    return false;
}

bool App::_pullStackCurrentScreen() {
    // если стэк пустой
    // то возвращаем false, иначе
    // восстанавливаем последний скрин
    if (m_stack_activity.empty()) {
        return false;
    }

    // устанавливаем id нового экрана
    m_opening = m_stack_activity.top();

    // удаляем его из стэка
    m_stack_activity.pop();

    // создаём новый экран
    _createNewActivity();

    return true;
}

void App::_activityTransaction() {
    // достаём intent, елси он есть
    Intent *intent = static_cast<Intent *>(m_store->getState().app_state.intent);

    // проверяем, есть ли он
    if (intent) {
        // если есть intent, значит нужно создать новый объект
        // сперва смотрим, нужно ли отправлять в стек текущий экран
        if (intent->push_stack) {
            // если нужно, делаем это
            _pushStackCurrentScreen();
        }

        // запускаем новый экран
        // удаляем старый
        delete m_current_activity;

        // кладём id нового экрана
        m_opening = intent->id_activity;

        // создаём новый экран
        _createNewActivity();

        // удаляем intent
        delete intent;

        // обнуляем state
        m_store->dispatch(clearIntentOpenActivity());
    } else {
        // если не нужно открывать, пытаемся достать что - то из стека
        if (bool err = _pullStackCurrentScreen(); !err) {
            // если стэк пуст, значит закрылся последний экран программы
            // придётся её закрыть
            m_is_running = false;
        }
    }
}

void App::_createNewActivity() {
    // TODO: добавляем сюда записи о новых экранах

    switch (m_opening) {
        case Activity::MAIN: {
            m_current_activity = new MainActivity();
            break;
        }
        case Activity::LOADING: {
            m_current_activity = new LoadingActivity();
            break;
        }
        case Activity::ALARM_CLOCK: {
            m_current_activity = new AlarmClockActivity();
            break;
        }
    }
}
