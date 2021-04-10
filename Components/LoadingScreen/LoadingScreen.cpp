#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_LOAD_SCREEN);
    m_background_sprite.setTexture(m_background_texture);

    m_font.loadFromFile(PATH_FONT_TEXT);
    m_text_version.setFont(m_font);
    m_text_version.setString("ALPHA VERSION 0.6");
    m_text_version.setCharacterSize(18);
    m_text_version.setPosition(Vector2f(28, 451));
    m_text_version.setFillColor(Color(96, 125, 139));
}

void LoadingScreen::render(RenderWindow *window) {
    BaseComponent::render(window);

    window->draw(m_text_version);
}
