#ifndef CLOCK_MAINACTIVITY_H
#define CLOCK_MAINACTIVITY_H

#include<BaseActivity.h>


/*
 * Здесь описываются пункты меню
 */
enum class Items {
    CLOCK,
    ALARM_CLOCK,
    STOPWATCH,
    TIMER,
    SETTINGS
};

struct IntentItem {
    Items id_item{};
    void *data{};
};

class MainActivity : public BaseActivity {
public:
    MainActivity();

    MainActivity(const MainActivity &) = delete;

    MainActivity &operator=(const MainActivity &) = delete;
};


#endif //CLOCK_MAINACTIVITY_H
