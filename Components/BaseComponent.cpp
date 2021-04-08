#include "BaseComponent.h"

ID BaseComponent::s_generate_id{};

void BaseComponent::init() {
    // TODO: главный код компонента
}

void BaseComponent::render(RenderWindow *window) {
    // TODO: переопределить в производных классах

    window->draw(m_background_sprite);
}

BaseComponent *BaseComponent::select(Event::MouseMoveEvent mouse_move) {
    // TODO: переопределить в производных классах

    bool is_select = m_background_sprite.getGlobalBounds().contains(mouse_move.x, mouse_move.y);

    return is_select ? this : nullptr;
}

void BaseComponent::click() {
    if (m_click_listener) {
        m_click_listener(this);
    }
}

void BaseComponent::setState(StateComponent state_component) {
    m_state_component = state_component;
}

StateComponent BaseComponent::getState() {
    return StateComponent::DISABLED;
}

void BaseComponent::setPosition(Vector2i position) {
    m_position = position;
}

Vector2i BaseComponent::getPosition() {
    return sf::Vector2i();
}

void BaseComponent::setClickListener(Callback click_listener) {
    m_click_listener = click_listener;
}

ID BaseComponent::getId() {
    return m_id;
}

BaseComponent::BaseComponent() {
    m_id = s_generate_id++;
}
