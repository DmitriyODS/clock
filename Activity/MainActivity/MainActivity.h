#ifndef CLOCK_MAINACTIVITY_H
#define CLOCK_MAINACTIVITY_H

#include <BaseActivity.h>
#include <Menu/Menu.h>
#include <Clock/Clock.h>
#include <AlarmClock/AlarmClock.h>
#include <Stopwatch/Stopwatch.h>
#include <Timer/Timer.h>
#include <MainMenu/actions/actions.h>


class MainActivity : public BaseActivity {
public:
    MainActivity();

    MainActivity(const MainActivity &) = delete;

    MainActivity &operator=(const MainActivity &) = delete;

    void _initComponents() override;
};


#endif //CLOCK_MAINACTIVITY_H
