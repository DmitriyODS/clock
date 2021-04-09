#include "CardNotFound.h"

void CardNotFound::init() {
    BaseComponent::init();

    m_background_texture.loadFromFile(PATH_CARD_NOT_FOUND);
    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setPosition(Vector2f(786, 291));
}

void CardNotFound::render(RenderWindow *window) {
    if (!checkVisible()) return;

    BaseComponent::render(window);
}
