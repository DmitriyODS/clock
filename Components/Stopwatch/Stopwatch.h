#ifndef CLOCK_STOPWATCH_H
#define CLOCK_STOPWATCH_H

#include <BaseActivity.h>
#include <Button/Button.h>

class Stopwatch : public BaseComponent {
public:
    Stopwatch(Vector2f position, Vector2f size);

    Stopwatch(const Stopwatch &) = delete;

    Stopwatch &operator=(const Stopwatch &) = delete;

    void render(RenderWindow *window) override;

    BaseComponent * mouseCollision(Event::MouseMoveEvent mouse_move) override;

private:
    Font m_font{};
    Text m_text_title{};
    Font m_font_text{};
    Text m_text_time{};
    vector<Button *> m_buttons{};
};


#endif //CLOCK_STOPWATCH_H
