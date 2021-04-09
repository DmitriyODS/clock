#include "Menu.h"

void Menu::render(RenderWindow *window) {
    BaseComponent::render(window);

    IntentItem *intentItem = static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);

    for (auto *pItem : m_buttons) {
        if (intentItem->id_item == pItem->getMIdItem()) {
            pItem->setMSelected(true);
        } else {
            pItem->setMSelected(false);
        }

        pItem->render(window);
    }
}

BaseComponent *Menu::mouseCollision(Event::MouseMoveEvent mouse_move) {
    BaseComponent *cmpnt, *save{};

    for (auto &item : m_buttons) {
        cmpnt = item->mouseCollision(mouse_move);

        if (cmpnt) {
            save = cmpnt;
        }
    }

    return save;
}

Menu::Menu(Vector2f position, Vector2f size) : BaseComponent(position, size) {

    m_background_texture.loadFromFile(PATH_BACKGROUND_MENU);

    m_background_sprite.setTexture(m_background_texture);

    m_background_sprite.setPosition(m_position);

    auto *button = new Button("Clock", Vector2f(24, 190), Vector2f(470, 94));
    button->setMIdItem(Items::CLOCK);
    button->setClickListener([this](void *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::CLOCK};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Alarm clock", Vector2f(24, 316), Vector2f(470, 94));
    button->setMIdItem(Items::ALARM_CLOCK);
    button->setClickListener([this](void *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::ALARM_CLOCK};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Stopwatch", Vector2f(24, 442), Vector2f(470, 94));
    button->setMIdItem(Items::STOPWATCH);
    button->setClickListener([this](void *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Timer", Vector2f(24, 568), Vector2f(470, 94));
    button->setMIdItem(Items::TIMER);
    button->setClickListener([this](void *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();

    m_buttons.push_back(button);

    button = new Button("Settings", Vector2f(24, 694), Vector2f(470, 94));
    button->setMIdItem(Items::SETTINGS);
    button->setClickListener([this](void *) {
        delete static_cast<IntentItem *>(m_store->getState().main_menu_state.intent_item);
        auto *intentItem = new IntentItem{Items::NOT_FOUND};
        m_store->dispatch(selectItemMenu(intentItem));
    });
    button->init();
    m_buttons.push_back(button);

    button = new Button("Exit", Vector2f(24, 820), Vector2f(470, 94));
    button->setClickListener([this](void *) {
        m_store->dispatch(setExit());
    });
    button->init();

    m_buttons.push_back(button);
}

void Menu::clickListener(void *component) {
}
