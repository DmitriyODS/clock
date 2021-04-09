#ifndef CLOCK_BASECOMPONENT_H
#define CLOCK_BASECOMPONENT_H

#include <vector>
#include <globalTypes.h>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <Store.h>

using sf::RenderWindow;
using sf::Vector2i;
using sf::Vector2f;
using sf::Event;
using sf::Sprite;
using sf::Texture;
using std::function;
using std::string;

using std::vector;
using sf::Font;
using sf::Text;


class BaseComponent;

//// состояния компонента
enum class StateComponent {
    DEFAULT,
    FOCUS,
    SELECTED,
    DISABLED
};

using Callback = function<void(void *)>;


class BaseComponent {
public:
    BaseComponent(Vector2f position, Vector2f size);

    BaseComponent(const BaseComponent &) = delete;

    BaseComponent &operator=(const BaseComponent &) = delete;

    virtual void render(RenderWindow *window);

    virtual BaseComponent *mouseCollision(Event::MouseMoveEvent mouse_move);

    virtual void mousePressed(Event::MouseButtonEvent mouse_pressed);

    virtual void mouseReleased(Event::MouseButtonEvent mouse_pressed);

    virtual void setDisabled(bool value);

    virtual bool isEnabled();

    virtual void click();

    virtual void setState(StateComponent state_component);

    virtual StateComponent getState();

    virtual void setPosition(Vector2f position);

    virtual Vector2f getPosition();

    virtual void setClickListener(Callback click_listener);

    virtual void init();

    virtual ID getId();

    virtual bool checkVisible();

    virtual Items getMIdItem() const;

    virtual void setMIdItem(Items mIdItem);

    virtual void updateStyle();

    virtual const Vector2f &getMSize() const;

    virtual void setMSize(const Vector2f &mSize);

    virtual bool checkCollision(Event::MouseMoveEvent mouse_move);

protected:
    static ID s_generate_id;

    ID m_id{};
    ColorApp m_color_app{};
    Texture m_background_texture{};
    Sprite m_background_sprite{};
    StateComponent m_state_component{};
    Vector2f m_position{};
    Vector2f m_size{};

    Callback m_click_listener{};
    Store *m_store{};

    Items m_id_item{};
};

using ComponentsList = vector<BaseComponent *>;


#endif //CLOCK_BASECOMPONENT_H
