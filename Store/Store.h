#ifndef CLOCK_STORE_H
#define CLOCK_STORE_H

#include <State.h>
#include <reducers.h>
#include <functional>
#include <vector>
#include <iostream>

//// шаблон функции подписчика
using Subscrabe = std::function<void()>;

//// лист функций подписчиков
using Subscrabes = std::vector<Subscrabe>;

class Store {
public:
    Store() = delete;

    Store(const Store &) = delete;

    Store &operator=(const Store &) = delete;

    //// создаём объект хранилища
    static Store *createStore(Reducer reducer);

    //// возвращаем объект хранилища
    static Store *getStore();

    //// возвращаем состояние
    State getState();

    //// добавляем нового подписчика
    void subscrabe(Subscrabe callback);

    //// вызываем событие
    void dispatch(Action action);

private:
    explicit Store(Reducer reducer);

    State m_state{};
    Subscrabes m_subscrabes{};
    Reducer m_reducer{};

    static Store *m_store;

    //// выполняет начальную инициализацию
    void _init();
};


#endif //CLOCK_STORE_H
