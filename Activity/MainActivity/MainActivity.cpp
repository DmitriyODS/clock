#include "MainActivity.h"

MainActivity::MainActivity()
        : BaseActivity(
        Activity::MAIN,
        "Clock Master",
        VideoMode::getDesktopMode(),
        StyleWindow::Fullscreen
) {}

void MainActivity::_initComponents() {
    BaseActivity::_initComponents();

    auto *intentItem = new IntentItem{Items::CLOCK};
    m_store->dispatch(selectItemMenu(intentItem));

    auto *menu = new Menu();
    menu->init();

    auto *clock_screen = new Clock();
    clock_screen->setMIdItem(Items::CLOCK);
    clock_screen->init();

    auto *card_not_found = new CardNotFound();
    card_not_found->setMIdItem(Items::NOT_FOUND);
    card_not_found->init();

    auto *alarm_clock = new AlarmClockScreen();
    // TODO: доделать

    m_components.push_back(menu);
    m_components.push_back(clock_screen);
    m_components.push_back(alarm_clock);
    m_components.push_back(card_not_found);
}
