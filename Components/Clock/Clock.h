#ifndef CLOCK_CLOCK_H
#define CLOCK_CLOCK_H

#include <BaseComponent.h>
#include <ctime>


using sf::RectangleShape;

class Clock : public BaseComponent {
public:
    Clock() = default;

    Clock(const Clock &) = delete;

    Clock &operator=(const Clock &) = delete;

    void init() override;

    void render(RenderWindow *window) override;

    void updateClock();

private:

    Texture m_texture_clock{};
    Sprite m_sprite_clock{};

    Texture m_texture_clock_point{};
    Sprite m_sprite_clock_point{};

    RectangleShape m_arrow_hour{};
    RectangleShape m_arrow_minutes{};
    RectangleShape m_arrow_seconds{};
};


#endif //CLOCK_CLOCK_H
