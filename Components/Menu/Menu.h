#ifndef CLOCK_MENU_H
#define CLOCK_MENU_H

#include <BaseComponent.h>
#include <Button/Button.h>
#include <MainMenu/actions/actions.h>
#include <App/actions/actions.h>

class Menu : public BaseComponent {
public:
    Menu() = default;

    Menu(const Menu &) = delete;

    Menu &operator=(const Menu &) = delete;

    void init() override;

    vector<Button*> m_buttons{};

    void render(RenderWindow *window) override;

    BaseComponent * select(Event::MouseMoveEvent mouse_move) override;
};


#endif //CLOCK_MENU_H
