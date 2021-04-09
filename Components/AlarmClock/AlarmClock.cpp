#include "AlarmClock.h"

void AlarmClockScreen::init() {
    BaseComponent::init();

    m_background_texture.loadFromFile(PATH_CARD_NOT_FOUND);
    m_background_sprite.setTexture(m_background_texture);
}
