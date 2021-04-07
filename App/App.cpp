#include "App.h"

void App::_init() {
    // создание объектов активностей
    m_map_activity = new MapActivity{
            {IDActivity::MAIN,               MainActivity::createActivity()},
            {IDActivity::LOADING,            LoadingActivity::createActivity()},
            {IDActivity::ALARM_CLOCK_SIGNAL, AlarmClockActivity::createActivity()}
    };

    m_current_activity = m_map_activity->at(IDActivity::LOADING);
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
        m_current_activity->start();

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
        m_stack_activity.push(m_current_activity);
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

    // возвращаем указатель на последний экран
    m_current_activity = m_stack_activity.top();

    // удаляем его из стэка
    m_stack_activity.pop();

    return true;
}

void App::_activityTransaction() {
    // проверяем, нужно ли запускать другой экран
    if (m_store->getState().app_state.intent_open_activity) {
        // если нужно, чекаем, слеудет ли сохранять текущий экран
        // в стэк
        if (m_store->getState().app_state.intent_push_activity) {
            // если да, то сохраняем текущий экран в стеке
            _pushStackCurrentScreen();

            // теперь обнуляем состояние помещения в стек
            // отправляем наше действие в диспач
            // данные оставляем пустыми
            // метод диспач у объекта store
            // принимает объект Action
            // этот объект содержит два поля: тип события
            // и данные
            // в данном случае, мы заполняем только тип
            // события, т к данные в нашем контексте не играют роли
            m_store->dispatch(clearPushStackActivity());
        }

        // теперь нужно запустить новый экран, помещаем его в текущий
        // для этого мы берём у хранилища указатель на следующий экран
        // который был помещён туда предыдущим экраном
        // преобразовываем неопределённый указатель void
        // в указатель на новый экран
        // и кладём в текущий
        m_current_activity = m_map_activity->at(*m_store->getState().app_state.intent_open_activity);

        // обнуляем указатель на следующий экран
        // отправляем действие в диспач
        // данные не заполняем
        m_store->dispatch(clearIntentOpenActivity());
    } else {
        // если не нужно запускать другой экран
        // пытаемся получить прошлый экран из стэка
        if (bool err = _pullStackCurrentScreen(); !err) {
            // если стэк пуст, значит закрылся последний экран программы
            // придётся её закрыть
            m_is_running = false;
        }

        // если получили прошлый экран и заменили им текущий
        // значит всё хорошо
    }
}
