#ifndef CLOCK_STOPWATCH_H
#define CLOCK_STOPWATCH_H

#include <BaseActivity.h>

class Stopwatch : public BaseComponent {
public:
    Stopwatch(Vector2f position, Vector2f size);

    Stopwatch(const Stopwatch &) = delete;

    Stopwatch &operator=(const Stopwatch &) = delete;
};


#endif //CLOCK_STOPWATCH_H
