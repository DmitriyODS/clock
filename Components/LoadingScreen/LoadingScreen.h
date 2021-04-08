#ifndef CLOCK_LOADINGSCREEN_H
#define CLOCK_LOADINGSCREEN_H

#include <BaseComponent.h>

class LoadingScreen : public BaseComponent {
public:
    LoadingScreen() = default;

    LoadingScreen(const LoadingScreen &) = delete;

    LoadingScreen &operator=(const LoadingScreen &) = delete;

    void init() override;
};


#endif //CLOCK_LOADINGSCREEN_H
