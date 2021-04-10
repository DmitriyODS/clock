#ifndef CLOCK_GLOBALTYPES_H
#define CLOCK_GLOBALTYPES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <ctime>

using sf::Color;
using sf::Uint32;
using std::map;

using std::vector;

//// тип времени
using ClockTime = std::time_t;

//// тип id
using ID = unsigned int;

/*
 * Храним главные цвета приложения
 */
struct ColorApp {
    Color background{};
    Color element_background{};
    Color text{};
    Color elements{};
    Color accent{};
    Color hover{};
    Color disabled{};
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

/*
 * Здесь описываются пункты меню
 */
enum Items : int {
    NONE,
    CLOCK,
    ALARM_CLOCK,
    STOPWATCH,
    TIMER,
    SETTINGS,
    NOT_FOUND
};

struct IntentItem {
    Items id_item{};
    ID id_button{};
    void *data{};
};

//// Лист будильников
using AlarmClocks = vector<AlarmClock *>;

extern const char *PATH_CLOCK_LOAD;

extern const char *PATH_BACKGROUND_LOADING_SCREEN;

extern const char *PATH_BACKGROUND_CARD;

extern const char *PATH_BACKGROUND_MENU;

extern const char *PATH_FONT_TEXT;

extern const char *PATH_CLOCK_FACE_1;

extern const char *PATH_CLOCK_POINT_1;

extern const char *PATH_CARD_NOT_FOUND;

extern const char *PATH_AVAILABLE_SETTINGS;

extern const char *PATH_CARD_VERSION;

extern const char *PATH_CARD_ABOUT;

extern const char *PATH_LOAD_SCREEN;

#endif //CLOCK_GLOBALTYPES_H
