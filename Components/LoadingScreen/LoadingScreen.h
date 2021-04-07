#ifndef CLOCK_LOADINGSCREEN_H
#define CLOCK_LOADINGSCREEN_H

#include <BaseComponent.h>

class LoadingScreen : public BaseComponent {
public:
    LoadingScreen();

    explicit LoadingScreen(Vector2i position);

    void render(RenderWindow *parent) override;

private:
    Vector2i m_position{};

    Sprite m_background{};

    Texture m_texture_background{};

    Sprite m_clock_load{};

    Texture m_texture_clock_load{};

    void _init();
};


#endif //CLOCK_LOADINGSCREEN_H
