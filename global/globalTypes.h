#ifndef CLOCK_GLOBALTYPES_H
#define CLOCK_GLOBALTYPES_H

#include <SFML/Graphics.hpp>

using sf::Color;
using sf::Uint32;

/*
 * Храним главные цвета приложения
 */
struct ColorApp {
    Color background{};
    Color text{};
    Color elements{};
    Color accent{};
};

/*
 * Храним циферблаты приложения
 */
struct ColorClock {
    Color hour{};
    Color minutes{};
    Color seconds{};
};

/*
 * Храним, размеры окна
 */
struct Size {
    Uint32 width;
    Uint32 height;
};

#endif //CLOCK_GLOBALTYPES_H
