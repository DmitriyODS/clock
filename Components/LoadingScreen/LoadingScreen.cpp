// FIXME: Не понятно почему, но при вставки этого инклуда в загловок
//  мы падаем с множественным включением
//  так всё работает, нужно исправить
#include <paths.h>
#include "LoadingScreen.h"

void LoadingScreen::_init() {
    m_texture_background.loadFromFile(PATH_BACKGROUND_LOADING_SCREEN);
    m_texture_clock_load.loadFromFile(PATH_CLOCK_LOAD);

    m_background.setTexture(m_texture_background);
    m_clock_load.setTexture(m_texture_clock_load);

    m_clock_load.setPosition(32, 32);
}

void LoadingScreen::render(RenderWindow *parent) {
    parent->draw(m_background);
    parent->draw(m_clock_load);
}

LoadingScreen::LoadingScreen(Vector2i position)
        : m_position(position) {
    _init();
}

LoadingScreen::LoadingScreen() : LoadingScreen(Vector2i{}) {}
