#ifndef CLOCK_LOADINGACTIVITY_H
#define CLOCK_LOADINGACTIVITY_H

#include <BaseActivity.h>
#include <LoadingScreen/LoadingScreen.h>


class LoadingActivity : public BaseActivity {
public:
    LoadingActivity();

    LoadingActivity(const LoadingActivity &) = delete;

    LoadingActivity &operator=(const LoadingActivity &) = delete;

    void start() override;

    void _createIntent() override;

    void _initComponents() override;

};


#endif //CLOCK_LOADINGACTIVITY_H
