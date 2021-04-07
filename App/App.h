#ifndef CLOCK_APP_H
#define CLOCK_APP_H

#include <Store.h>
#include <reducers.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <AlarmClockActivity/AlarmClockActivity.h>
#include <LoadingActivity/LoadingActivity.h>
#include <MainActivity/MainActivity.h>
#include <stack>
#include <daemons.h>
#include <Clock/actions/actions.h>
#include <AlarmClock/actions/actions.h>
#include <App/actions/actions.h>


using StackActivity = std::stack<BaseActivity *>;

using sf::Thread;

/*
 * Главный класс программы - синглтон
 */
class App {
public:
    App(const App &) = delete;

    App &operator=(const App &) = delete;

    static App &createApp();

    int start();

private:
    Store *m_store{};

    MapActivity *m_map_activity{};

    BaseActivity *m_current_activity{};

    StackActivity m_stack_activity{};

    bool m_is_running{};

    App();

    void _init();

    void _activityTransaction();

    bool _pushStackCurrentScreen();

    bool _pullStackCurrentScreen();

};


#endif //CLOCK_APP_H
