#ifndef CLOCK_BUTTON_H
#define CLOCK_BUTTON_H

#include <BaseComponent.h>


using sf::RectangleShape;

class Button : public BaseComponent {
public:
    Button(string text, Vector2f size, unsigned int size_text);

    Button(const Button &) = delete;

    Button &operator=(const Button &) = delete;

    void init() override;

    void setSize(Vector2f size, unsigned int size_text);

    Vector2f getSize();

    void render(RenderWindow *window) override;

    void setPosition(Vector2f position) override;

    void setSelect();

    void setFocus();

    void clearSelect();

    BaseComponent * select(Event::MouseMoveEvent mouse_move) override;

private:
    Vector2f m_size{};

    RectangleShape m_react_back{};

    Font m_font{};

    Text m_text{};

    Items m_item_id{};
public:
    Items getMItemId() const;

    void setMItemId(Items mItemId);
};

#endif //CLOCK_BUTTON_H
