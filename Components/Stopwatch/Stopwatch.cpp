#include "Stopwatch.h"

Stopwatch::Stopwatch(Vector2f position, Vector2f size) : BaseComponent(position, size) {
    m_background_texture.loadFromFile(PATH_CARD_STOPWATCH);
    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setPosition(m_position);

    m_font.loadFromFile(PATH_FONT_TITLE_TEXT);
    m_font_text.loadFromFile(PATH_FONT_TEXT);
    m_text_title.setFont(m_font);
    m_text_title.setPosition(989, 251);
    m_text_title.setCharacterSize(48);
    m_text_title.setFillColor(Color(96, 125, 139));
    m_text_title.setString("Stopwatch");

    m_text_time.setFont(m_font_text);
    m_text_time.setFillColor(Color(96, 125, 139));
    m_text_time.setPosition(Vector2f(1059, 392));
    m_text_time.setCharacterSize(120);

    auto *button = new Button("Start", Vector2f(1019, 641), Vector2f(160, 60));

    m_buttons.push_back(button);

    button = new Button("Stop", Vector2f(1315, 641), Vector2f(160, 60));

    m_buttons.push_back(button);

    button = new Button("Reset", Vector2f(1139, 734), Vector2f(215, 60));
    button->setClickListener([this](void *) {
        m_store->dispatch(setExit());
    });

    m_buttons.push_back(button);
}

void Stopwatch::render(RenderWindow *window) {
    if (!checkVisible()) return;

    BaseComponent::render(window);
    window->draw(m_text_title);
    window->draw(m_text_time);

    for (auto *pItem : m_buttons) {
        pItem->render(window);
    }
}

BaseComponent *Stopwatch::mouseCollision(Event::MouseMoveEvent mouse_move) {
    BaseComponent *cmpnt, *save{};

    for (auto &item : m_buttons) {
        cmpnt = item->mouseCollision(mouse_move);

        if (cmpnt) {
            save = cmpnt;
        }
    }

    return save;
}
