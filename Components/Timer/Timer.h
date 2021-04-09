#ifndef CLOCK_TIMER_H
#define CLOCK_TIMER_H

#include <BaseComponent.h>

class Timer : public BaseComponent {
public:
    Timer(Vector2f position, Vector2f size);

    Timer(const Timer &) = delete;

    Timer &operator=(const Timer &) = delete;
};


#endif //CLOCK_TIMER_H
