#ifndef CLOCK_BASEACTIVITY_H
#define CLOCK_BASEACTIVITY_H

#include <iostream>
#include <string>
#include <Store.h>
#include <globalTypes.h>
#include <activity.h>
#include <SFML/Graphics.hpp>
#include <daemons.h>
#include <App/actions/actions.h>
#include <BaseComponent.h>

using std::string;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::Thread;
using sf::Mouse;

namespace StyleWindow = sf::Style;

/*
 * Базовый класс, описывающий активность
 */
class BaseActivity {
public:
    BaseActivity() = delete;

    BaseActivity(const BaseActivity &) = delete;

    BaseActivity &operator=(const BaseActivity &) = delete;

    BaseActivity(Activity id_activity, string title, VideoMode video_mode, Uint32 style_window);

    virtual void start();

    virtual void render();

    virtual void selectComponent(Event::MouseMoveEvent mouse_move);

    virtual void clickComponent(Mouse::Button button);

    virtual Activity getId();

    virtual ~BaseActivity();

protected:
    Activity m_id_activity{};
    RenderWindow *m_window{};
    VideoMode m_video_mode{};
    ComponentsList m_components{};
    string m_title_window{};
    Store *m_store{};
    Thread *m_thread_render{};
    bool m_is_running{};
    Uint32 m_style_window{};
    ColorApp m_color_app{};

    virtual void _init();

    virtual void _initWindow();

    virtual void _reinitWindow();

    virtual void _initComponents();

    virtual void _initThreadRender();

    virtual void _preparingActivity();

    virtual void _createIntent();
};

/*
 * Intent
 * id_activity - активность, которую следует открыть
 * data - данные, которые мы передаём другой активности
 * push_stack - флаг о сохранении в стек текущей активности
 */
struct Intent {
    Activity id_activity{};
    void *data{};
    bool push_stack{};
};

#endif //CLOCK_BASEACTIVITY_H
