#ifndef CLOCK_ALARMCLOCKACTIVITY_H
#define CLOCK_ALARMCLOCKACTIVITY_H

#include <BaseActivity.h>


class AlarmClockActivity : public BaseActivity {
public:
    AlarmClockActivity(const AlarmClockActivity &) = delete;

    AlarmClockActivity &operator=(const AlarmClockActivity &) = delete;

    static AlarmClockActivity *createActivity();

    void start(MapActivity *map_activity) override;

    void render() override;

private:
    Store *m_store{};

    AlarmClockActivity();

    void _init();
};


#endif //CLOCK_ALARMCLOCKACTIVITY_H
