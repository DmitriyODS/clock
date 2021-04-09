#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_BACKGROUND_LOADING_SCREEN);
    m_background_sprite.setTexture(m_background_texture);
}
