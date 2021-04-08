#ifndef CLOCK_MAINACTIVITY_H
#define CLOCK_MAINACTIVITY_H

#include<BaseActivity.h>


class MainActivity : public BaseActivity {
public:
    MainActivity(const MainActivity &) = delete;

    MainActivity &operator=(const MainActivity &) = delete;

    static MainActivity *createActivity();

    void render() override;

    void start(MapActivity *map_activity) override;

private:
    Store *m_store{};

    bool m_is_running{};

    RenderWindow *m_window{};

    VideoMode m_video_mode{};

    MainActivity();

    void _init();
};


#endif //CLOCK_MAINACTIVITY_H
