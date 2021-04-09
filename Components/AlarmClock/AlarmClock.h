#ifndef CLOCK_ALARMCLOCK_H
#define CLOCK_ALARMCLOCK_H

#include <BaseComponent.h>

class AlarmClockScreen : public BaseComponent {
public:
    AlarmClockScreen() = default;

    AlarmClockScreen(const AlarmClockScreen &) = delete;

    AlarmClockScreen &operator=(const AlarmClockScreen &) = delete;

    void init() override;

private:
    Items m_id_item{};
};


#endif //CLOCK_ALARMCLOCK_H
