#include "BaseComponent.h"

ID BaseComponent::s_generate_id{};

void BaseComponent::init() {
    // TODO: главный код компонента
}

void BaseComponent::render(RenderWindow *window) {
    // TODO: переопределить в производных классах

    window->draw(m_background_sprite);
}

BaseComponent *BaseComponent::mouseCollision(Event::MouseMoveEvent mouse_move) {
    if (m_state_component == StateComponent::DISABLED) return nullptr;

    bool is_select = checkCollision(mouse_move);

    if (is_select) {
        m_state_component = StateComponent::FOCUS;
        return this;
    }

    m_state_component = StateComponent::DEFAULT;

    return nullptr;
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

void BaseComponent::setPosition(Vector2f position) {
    m_position = position;
}

Vector2f BaseComponent::getPosition() {
    return m_position;
}

void BaseComponent::setClickListener(Callback click_listener) {
    m_click_listener = click_listener;
}

ID BaseComponent::getId() {
    return m_id;
}

bool BaseComponent::checkVisible() {
    Items *id_item = static_cast<Items *>(m_store->getState().main_menu_state.intent_item);

    return *id_item == getMIdItem();
}

Items BaseComponent::getMIdItem() const {
    return m_id_item;
}

void BaseComponent::setMIdItem(Items mIdItem) {
    m_id_item = mIdItem;
}

void BaseComponent::updateStyle() {
    m_color_app = m_store->getState().app_state.color_app;
}

BaseComponent::BaseComponent(Vector2f position, Vector2f size)
        : m_position(position), m_size(size) {
    m_id = s_generate_id++;

    m_store = Store::getStore();
}

void BaseComponent::mouseReleased(Event::MouseButtonEvent mouse_pressed) {
    if (m_state_component == StateComponent::DISABLED) return;

    if (m_state_component == StateComponent::SELECTED) {
        m_state_component = StateComponent::DEFAULT;
        click();
    }
}

void BaseComponent::mousePressed(Event::MouseButtonEvent mouse_pressed) {
    if (m_state_component == StateComponent::DISABLED) return;

    if (m_state_component == StateComponent::FOCUS) {
        m_state_component = StateComponent::SELECTED;
    }
}

void BaseComponent::setDisabled(bool value) {
    m_state_component = value ? StateComponent::DISABLED : StateComponent::DEFAULT;
}

bool BaseComponent::isEnabled() {
    return m_state_component != StateComponent::DISABLED;
}

const Vector2f &BaseComponent::getMSize() const {
    return m_size;
}

void BaseComponent::setMSize(const Vector2f &mSize) {
    m_size = mSize;
}

bool BaseComponent::checkCollision(Event::MouseMoveEvent mouse_move) {
    // TODO: переопределить в производных классах

    return m_background_sprite.getGlobalBounds().contains(mouse_move.x, mouse_move.y);
}
