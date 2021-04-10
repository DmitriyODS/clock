#ifndef CLOCK_SETTINGS_H
#define CLOCK_SETTINGS_H


#include <BaseComponent.h>

class Settings : public BaseComponent {
public:
    Settings(Vector2f position, Vector2f size);

    Settings(const Settings &) = delete;

    Settings &operator=(const Settings &) = delete;

    void render(RenderWindow *window) override;

private:
    Texture m_card_about{};
    Sprite m_card_about_sprite{};
    Texture m_card_settings{};
    Sprite m_settings_sprite{};
    Font m_font{};
    Text m_text_about_title{};
    Text m_text_about{};
    Text m_text_develop{};
    Text m_version_title{};
    Text m_version{};
    Text m_build{};
};


#endif //CLOCK_SETTINGS_H
