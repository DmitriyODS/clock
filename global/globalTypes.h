#ifndef CLOCK_GLOBALTYPES_H
#define CLOCK_GLOBALTYPES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

using sf::Color;
using sf::Uint32;
using std::map;

using std::vector;

//// тип времени
using ClockTime = time_t;

//// тип id
using ID = unsigned int;

//// Id activity
enum class IDActivity {
    LOADING,
    MAIN,
    ALARM_CLOCK_SIGNAL
};

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
    Color text{};
    Color background{};
};

/*
 * Храним, размеры окна
 */
struct Size {
    Uint32 width;
    Uint32 height;
};

/*
 * Тип будильника
 */
struct AlarmClock {
    static ID current_id;

    ID id{};
    int position{};
    ClockTime end_time{};
    bool enabled{};
};

//// Лист будильников
using AlarmClocks = vector<AlarmClock *>;

//// Id пунктов главного меню
enum class ItemMenuId {
    CLOCK,
    ALARM_CLOCK,
    STOPWATCH,
    TIMER,
    SETTINGS
};

#endif //CLOCK_GLOBALTYPES_H
