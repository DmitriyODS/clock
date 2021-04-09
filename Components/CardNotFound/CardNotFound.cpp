#include "CardNotFound.h"

void CardNotFound::render(RenderWindow *window) {
    if (!checkVisible()) return;

    BaseComponent::render(window);
}

CardNotFound::CardNotFound(Vector2f position, Vector2f size)
        : BaseComponent(position, size) {

    m_background_texture.loadFromFile(PATH_CARD_NOT_FOUND);
    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setPosition(m_position);
}
