#ifndef CLOCK_LOADINGSCREEN_H
#define CLOCK_LOADINGSCREEN_H

#include <BaseComponent.h>

class LoadingScreen : public BaseComponent {
public:
    LoadingScreen(Vector2f position, Vector2f size);

    LoadingScreen(const LoadingScreen &) = delete;

    LoadingScreen &operator=(const LoadingScreen &) = delete;
};


#endif //CLOCK_LOADINGSCREEN_H
