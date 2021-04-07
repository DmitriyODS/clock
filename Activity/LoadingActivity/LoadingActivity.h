#ifndef CLOCK_LOADINGACTIVITY_H
#define CLOCK_LOADINGACTIVITY_H

#include <BaseActivity.h>
#include <LoadingScreen/LoadingScreen.h>


class LoadingActivity : public BaseActivity {
public:
    LoadingActivity(const LoadingActivity &) = delete;

    LoadingActivity &operator=(const LoadingActivity &) = delete;

    static LoadingActivity *createActivity();

    void start(MapActivity *map_activity) override;

    void render() override;

private:
    Store *m_store{};

    RenderWindow *m_window{};

    ComponentsList m_components{};

    bool m_is_runnning{};

    LoadingActivity();

    void _init();
};


#endif //CLOCK_LOADINGACTIVITY_H
