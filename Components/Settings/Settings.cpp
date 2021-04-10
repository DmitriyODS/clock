#include "Settings.h"

Settings::Settings(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_CARD_ABOUT);
    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setPosition(Vector2f(666, 45));

    m_card_about.loadFromFile(PATH_CARD_VERSION);
    m_card_about_sprite.setTexture(m_card_about);
    m_card_about_sprite.setPosition(Vector2f(1444, 45));

    m_card_settings.loadFromFile(PATH_AVAILABLE_SETTINGS);
    m_settings_sprite.setTexture(m_card_settings);
    m_settings_sprite.setPosition(Vector2f(666, 470));

    m_font.loadFromFile(PATH_FONT_TEXT);
    m_text_about.setFont(m_font);
    m_text_about_title.setFont(m_font);
    m_text_develop.setFont(m_font);
    m_build.setFont(m_font);
    m_version_title.setFont(m_font);
    m_version.setFont(m_font);

    m_text_about.setFillColor(Color(96, 125, 139));
    m_text_about_title.setFillColor(Color(96, 125, 139));
    m_text_develop.setFillColor(Color(96, 125, 139));
    m_build.setFillColor(Color(96, 125, 139));
    m_version_title.setFillColor(Color(96, 125, 139));
    m_version.setFillColor(Color(96, 125, 139));

    m_text_about_title.setString("About");
    m_text_about.setString("Application for working with time.");
    m_text_develop.setString("Developer - Osipovskiy DS");

    m_version_title.setString("Version");
    m_version.setString("Alpha version - 0.6");
    m_build.setString("Build - 210410");

    m_text_about.setPosition(Vector2f(719, 174));
    m_text_about_title.setPosition(Vector2f(692, 81));
    m_text_develop.setPosition(Vector2f(719, 347));
    m_build.setPosition(Vector2f(1487, 262));
    m_version_title.setPosition(Vector2f(1474, 81));
    m_version.setPosition(Vector2f(1487, 190));
}

void Settings::render(RenderWindow *window) {
    if (!checkVisible()) return;

    BaseComponent::render(window);
    window->draw(m_card_about_sprite);
    window->draw(m_settings_sprite);
    window->draw(m_text_about);
    window->draw(m_text_about_title);
    window->draw(m_text_develop);
    window->draw(m_build);
    window->draw(m_version_title);
    window->draw(m_version);
}
