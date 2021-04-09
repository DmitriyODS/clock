#include "Button.h"

void Button::init() {
    BaseComponent::init();

    m_react_back.setSize(m_size);
    m_react_back.setFillColor(Color::White);
    m_react_back.setOutlineColor(Color(112, 112, 112));
    m_react_back.setOutlineThickness(2);

    m_font.loadFromFile(PATH_FONT_TEXT);
    m_text.setFont(m_font);
    m_text.setFillColor(Color(112, 112, 112));

    m_react_back.setPosition(m_position);
    m_text.setPosition(m_position);
    m_text.move(32, 18);
}

Vector2f Button::getSize() {
    return m_size;
}

void Button::setSize(Vector2f size, unsigned int size_text) {
    m_size = size;
    m_text.setCharacterSize(size_text);
}

Button::Button(string text, Vector2f size, unsigned int size_text) {
    m_text.setString(text);
    m_size = size;
    m_text.setCharacterSize(size_text);
}

void Button::render(RenderWindow *window) {
    IntentItem *intentItem = static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);

    if (m_state_component == StateComponent::FOCUS) {
        setFocus();
    }

    window->draw(m_react_back);
    window->draw(m_text);
}

void Button::setPosition(Vector2f position) {
    BaseComponent::setPosition(position);

    m_react_back.setPosition(m_position);
    m_text.setPosition(m_position);
    m_text.move(32, 18);
}

void Button::setSelect() {
    m_react_back.setOutlineColor(Color(233, 30, 99));
    m_text.setFillColor(Color(233, 30, 99));
    m_react_back.setSize(Vector2f(m_size.x + 32, m_size.y));
    m_state_component = StateComponent::SELECTED;
}

void Button::clearSelect() {
    m_react_back.setOutlineColor(Color(112, 112, 112));
    m_text.setFillColor(Color(112, 112, 112));
    m_react_back.setSize(m_size);
    if (m_state_component != StateComponent::FOCUS) {
        m_state_component = StateComponent::NONE;
    }
}

Items Button::getMItemId() const {
    return m_item_id;
}

void Button::setMItemId(Items mItemId) {
    m_item_id = mItemId;
}

BaseComponent *Button::select(Event::MouseMoveEvent mouse_move) {
    bool is_select = m_react_back.getGlobalBounds().contains(mouse_move.x, mouse_move.y);

    if (is_select && m_state_component != StateComponent::SELECTED) {
        m_state_component = StateComponent::FOCUS;
        return this;
    } else {
        m_state_component = StateComponent::NONE;
    }

    return nullptr;
}

void Button::setFocus() {
    m_react_back.setOutlineColor(Color(33, 150, 243));
    m_text.setFillColor(Color(33, 150, 243));
}
