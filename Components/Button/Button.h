#ifndef CLOCK_BUTTON_H
#define CLOCK_BUTTON_H

#include <BaseComponent.h>


using sf::RectangleShape;

class Button : public BaseComponent {
public:
    Button(string text, Vector2f position, Vector2f size);

    Button(const Button &) = delete;

    Button &operator=(const Button &) = delete;

    void setMSize(const Vector2f &mSize) override;

    Vector2f getSize();

    void render(RenderWindow *window) override;

    void setPosition(Vector2f position) override;

    bool checkCollision(Event::MouseMoveEvent mouse_move) override;

    void calculateText();

    void updateButton();

    bool isMSelected() const;

    void setMSelected(bool mSelected);

    BaseComponent *mouseCollision(Event::MouseMoveEvent mouse_move) override;

    void mouseReleased(Event::MouseButtonEvent mouse_pressed) override;

    void mousePressed(Event::MouseButtonEvent mouse_pressed) override;

private:
    RectangleShape m_react_back{};

    unsigned int m_text_size{};

    Font m_font{};

    Text m_text{};

    bool m_selected{};
};

#endif //CLOCK_BUTTON_H
