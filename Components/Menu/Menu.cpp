#include "Menu.h"

void Menu::init() {
    BaseComponent::init();

    m_background_texture.loadFromFile(PATH_BACKGROUND_MENU);

    m_background_sprite.setTexture(m_background_texture);

    auto *button = new Button("Clock", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 190));
    button->setMItemId(Items::CLOCK);
    button->setClickListener([this](BaseComponent *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::CLOCK};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Alarm clock", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 316));
    button->setMItemId(Items::ALARM_CLOCK);
    button->setClickListener([this](BaseComponent *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::ALARM_CLOCK};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Stopwatch", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 442));
    button->setMItemId(Items::STOPWATCH);
    button->setClickListener([this](BaseComponent *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Timer", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 568));
    button->setMItemId(Items::TIMER);
    button->setClickListener([this](BaseComponent *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Settings", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 694));
    button->setMItemId(Items::SETTINGS);
    button->setClickListener([this](BaseComponent *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();
    m_buttons.push_back(button);

    button = new Button("Exit", Vector2f(470, 94), 48);
    button->setPosition(Vector2f(24, 820));
    button->setClickListener([this](BaseComponent *) {
        m_store->dispatch(setExit());
    });
    button->init();

    m_buttons.push_back(button);
}

void Menu::render(RenderWindow *window) {
    BaseComponent::render(window);

    IntentItem *intentItem = static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);

    for (auto *pItem : m_buttons) {
        if (intentItem->id_item == pItem->getMItemId()) {
            pItem->setSelect();
        } else {
            pItem->clearSelect();
        }

        pItem->render(window);
    }
}

BaseComponent *Menu::select(Event::MouseMoveEvent mouse_move) {
    for (auto *pItem : m_buttons) {
        BaseComponent *baseComponent = pItem->select(mouse_move);

        if (baseComponent) {
            return baseComponent;
        }
    }

    return nullptr;
}
