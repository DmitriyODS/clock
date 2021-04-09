// FIXME: Не понятно почему, но при вставки этого инклуда в загловок
//  мы падаем с множественным включением
//  так всё работает, нужно исправить
#include "LoadingScreen.h"


void LoadingScreen::init() {
    BaseComponent::init();

    m_background_texture.loadFromFile(PATH_BACKGROUND_LOADING_SCREEN);
    m_background_sprite.setTexture(m_background_texture);
}
