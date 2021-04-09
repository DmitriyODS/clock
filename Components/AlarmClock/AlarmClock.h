#ifndef CLOCK_ALARMCLOCK_H
#define CLOCK_ALARMCLOCK_H

#include <BaseComponent.h>

class AlarmClockScreen : public BaseComponent {
public:
    AlarmClockScreen(Vector2f position, Vector2f size);

    AlarmClockScreen(const AlarmClockScreen &) = delete;

    AlarmClockScreen &operator=(const AlarmClockScreen &) = delete;
};


#endif //CLOCK_ALARMCLOCK_H
