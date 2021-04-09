#ifndef CLOCK_CARDNOTFOUND_H
#define CLOCK_CARDNOTFOUND_H

#include <BaseComponent.h>

class CardNotFound : public BaseComponent {
public:
    CardNotFound(Vector2f position, Vector2f size);

    CardNotFound(const CardNotFound &) = delete;

    CardNotFound &operator=(const CardNotFound &) = delete;

    void render(RenderWindow *window) override;
};


#endif //CLOCK_CARDNOTFOUND_H
