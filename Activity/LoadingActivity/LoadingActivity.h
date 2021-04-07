#ifndef CLOCK_LOADINGACTIVITY_H
#define CLOCK_LOADINGACTIVITY_H

#include <BaseActivity.h>

class LoadingActivity : public BaseActivity {
public:
    LoadingActivity(const LoadingActivity &) = delete;

    LoadingActivity &operator=(const LoadingActivity &) = delete;

    static LoadingActivity *createActivity();

    void start() override;

    void render() override;

private:
    Store *m_store{};

    LoadingActivity();

    void _init();
};


#endif //CLOCK_LOADINGACTIVITY_H
