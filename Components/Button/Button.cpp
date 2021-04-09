#include "Button.h"

Vector2f Button::getSize() {
    return m_size;
}

void Button::render(RenderWindow *window) {
    updateButton();

    window->draw(m_react_back);
    window->draw(m_text);
}

void Button::setPosition(Vector2f position) {
    BaseComponent::setPosition(position);

    m_react_back.setPosition(m_position);
    calculateText();
}

bool Button::checkCollision(Event::MouseMoveEvent mouse_move) {
    return m_react_back.getGlobalBounds().contains(mouse_move.x, mouse_move.y);
}

Button::Button(string text, Vector2f position, Vector2f size)
        : BaseComponent(position, size) {

    m_font.loadFromFile(PATH_FONT_TEXT);
    m_text.setFont(m_font);
    m_text.setString(text);
    m_react_back.setSize(size);
    m_react_back.setPosition(position);
    m_react_back.setOutlineThickness(2);

    calculateText();
}

void Button::calculateText() {
    int w = (int) m_size.x / 6;
    int h = (int) m_size.y / 2;
    int res = std::min(w, h);
    m_text_size = res;
    m_text.setCharacterSize(m_text_size);

    w = (int) m_size.x / 2;
    h = (int) m_size.y / 2;

    int w_t = (int) m_text.getLocalBounds().width / 2;
    int h_t = (int) m_text.getLocalBounds().height / 2;

    w -= (w_t + 10);
    h -= (h_t + 10);

    m_text.setPosition(m_position.x + (float) w, m_position.y + (float) h);
}

void Button::updateButton() {
    m_color_app = m_store->getState().app_state.color_app;

    switch (m_state_component) {
        case StateComponent::DEFAULT: {
            m_text.setFillColor(m_color_app.text);
            m_react_back.setFillColor(m_color_app.element_background);
            m_react_back.setOutlineColor(m_color_app.elements);
            break;
        }
        case StateComponent::FOCUS: {
            m_text.setFillColor(m_color_app.hover);
            m_react_back.setFillColor(m_color_app.element_background);
            m_react_back.setOutlineColor(m_color_app.hover);
            break;
        }
        case StateComponent::SELECTED: {
            m_text.setFillColor(m_color_app.accent);
            m_react_back.setFillColor(m_color_app.element_background);
            m_react_back.setOutlineColor(m_color_app.accent);
            break;
        }
        case StateComponent::DISABLED: {
            m_text.setFillColor(m_color_app.text);
            m_react_back.setFillColor(m_color_app.disabled);
            m_react_back.setOutlineColor(m_color_app.elements);
            break;
        }
    }
}

void Button::setMSize(const Vector2f &mSize) {
    BaseComponent::setMSize(mSize);

    calculateText();
}

bool Button::isMSelected() const {
    return m_selected;
}

void Button::setMSelected(bool mSelected) {
    if (!m_selected && !mSelected) return;

    m_selected = mSelected;

    if (m_selected) {
        m_react_back.setSize(Vector2f(m_size.x + 40, m_size.y));
        m_state_component = StateComponent::SELECTED;
    } else {
        m_react_back.setSize(m_size);
        m_state_component = StateComponent::DEFAULT;
    }
}

BaseComponent *Button::mouseCollision(Event::MouseMoveEvent mouse_move) {
    if (!m_selected) {
        return BaseComponent::mouseCollision(mouse_move);
    }

    return nullptr;
}

void Button::mouseReleased(Event::MouseButtonEvent mouse_pressed) {
    if (!m_selected) {
        BaseComponent::mouseReleased(mouse_pressed);
    }

    click();
}

void Button::mousePressed(Event::MouseButtonEvent mouse_pressed) {
    if (!m_selected) {
        BaseComponent::mousePressed(mouse_pressed);
    }
}
