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

    bool m_is_runnning{};

    RenderWindow *m_window{};

    VideoMode m_video_mode{};

    ComponentsList m_components{};

    MainActivity();

    void _init();

    void _reinit();
};


#endif //CLOCK_MAINACTIVITY_H
