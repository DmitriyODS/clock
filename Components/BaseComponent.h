#ifndef CLOCK_BASECOMPONENT_H
#define CLOCK_BASECOMPONENT_H

#include <vector>
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Vector2i;
using sf::Sprite;
using sf::Texture;

using std::vector;


class BaseComponent {
public:
    virtual void render(RenderWindow *parent) = 0;
};

using ComponentsList = vector<BaseComponent *>;


#endif //CLOCK_BASECOMPONENT_H
