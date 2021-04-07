#ifndef CLOCK_BASEACTIVITY_H
#define CLOCK_BASEACTIVITY_H

#include <iostream>
#include <string>
#include <Store.h>
#include <globalTypes.h>
#include <SFML/Graphics.hpp>
#include <daemons.h>
#include <App/actions/actions.h>

using std::string;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::Thread;

namespace StyleWindow = sf::Style;

//// map activity
using MapActivity = map<IDActivity, void *>;

class BaseActivity {
public:
    virtual void start(MapActivity *map_activity) = 0;

    virtual void render() = 0;
};


#endif //CLOCK_BASEACTIVITY_H
