#ifndef CLOCK_ALARMCLOCKACTIVITY_H
#define CLOCK_ALARMCLOCKACTIVITY_H

#include <BaseActivity.h>


class AlarmClockActivity : public BaseActivity {
public:
    AlarmClockActivity();

    AlarmClockActivity(const AlarmClockActivity &) = delete;

    AlarmClockActivity &operator=(const AlarmClockActivity &) = delete;
};


#endif //CLOCK_ALARMCLOCKACTIVITY_H
