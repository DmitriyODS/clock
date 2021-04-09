#ifndef CLOCK_MENU_H
#define CLOCK_MENU_H

#include <BaseComponent.h>
#include <Button/Button.h>
#include <MainMenu/actions/actions.h>
#include <App/actions/actions.h>

class Menu : public BaseComponent {
public:
    Menu(Vector2f position, Vector2f size);

    Menu(const Menu &) = delete;

    Menu &operator=(const Menu &) = delete;

    vector<Button*> m_buttons{};

    void render(RenderWindow *window) override;

    void clickListener(void *component);

    BaseComponent * mouseCollision(Event::MouseMoveEvent mouse_move) override;
};


#endif //CLOCK_MENU_H
