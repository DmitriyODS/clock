#include "AlarmClock.h"

AlarmClockScreen::AlarmClockScreen(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_CARD_NOT_FOUND);
    m_background_sprite.setTexture(m_background_texture);
}
