#include "Clock.h"

void Clock::render(RenderWindow *window) {
    if (!checkVisible()) return;

    BaseComponent::render(window);

    updateClock();

    window->draw(m_sprite_clock);

    window->draw(m_arrow_seconds);
    window->draw(m_arrow_minutes);
    window->draw(m_arrow_hour);

    window->draw(m_sprite_clock_point);
}

void Clock::updateClock() {
    ClockTime clockTime = m_store->getState().clock_state.current_time;
    tm clock_tm = *localtime(&clockTime);

    float lambda_min = ((float) clock_tm.tm_min * 60 + (float) clock_tm.tm_sec) * 0.1f;
    auto lambda_hour = (float) ((float) ((clock_tm.tm_hour * 3600) + (clock_tm.tm_min * 60) + clock_tm.tm_sec) / 120);

    m_arrow_seconds.setRotation(180 + (float) (clock_tm.tm_sec * 6));
    m_arrow_minutes.setRotation(180 + lambda_min);
    m_arrow_hour.setRotation(180 + lambda_hour);
}

Clock::Clock(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_BACKGROUND_CARD);
    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setPosition(m_position);

    m_texture_clock.loadFromFile(PATH_CLOCK_FACE_1);
    m_sprite_clock.setTexture(m_texture_clock);
    m_sprite_clock.setPosition(Vector2f(991, 228));

    m_texture_clock_point.loadFromFile(PATH_CLOCK_POINT_1);
    m_sprite_clock_point.setTexture(m_texture_clock_point);
    m_sprite_clock_point.setPosition(Vector2f(1251, 488));

    m_arrow_hour.setSize(Vector2f(6, 90));
    m_arrow_minutes.setSize(Vector2f(6, 136));
    m_arrow_seconds.setSize(Vector2f(6, 198));

    m_arrow_hour.setFillColor(Color(233, 30, 99));
    m_arrow_minutes.setFillColor(Color::White);
    m_arrow_seconds.setFillColor(Color(255, 193, 7));

    m_arrow_hour.setPosition(Vector2f(1306, 545));
    m_arrow_minutes.setPosition(Vector2f(1306, 545));
    m_arrow_seconds.setPosition(Vector2f(1306, 545));
}
