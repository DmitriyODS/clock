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

    auto *menu = new Menu(Vector2f(), Vector2f());

    auto *clock_screen = new Clock(Vector2f(926, 180), Vector2f());
    clock_screen->setMIdItem(Items::CLOCK);

    auto *card_not_found = new CardNotFound(Vector2f(782, 291), Vector2f());
    card_not_found->setMIdItem(Items::NOT_FOUND);

    auto *alarm_clock = new AlarmClockScreen(Vector2f(1004, 236), Vector2f(573, 609));
    // TODO: доделать

    m_components.push_back(menu);
    m_components.push_back(clock_screen);
//    m_components.push_back(alarm_clock);
    m_components.push_back(card_not_found);
}
