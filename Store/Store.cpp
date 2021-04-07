#include "Store.h"

// инициализируем указатель на объект стора
// нулевым указателем
Store *Store::m_store{};

void Store::_init() {
    m_state = m_reducer(
            State{},
            Action{ActionTypes::INITIAL_STATE, ReducerTypes::ALL}
    );
}

Store::Store(Reducer reducer)
        : m_reducer(reducer) {
    _init();
}

Store *Store::createStore(Reducer reducer) {
    m_store = new Store(reducer);

    return m_store;
}

Store *Store::getStore() {
    if (m_store == nullptr) {
        std::cerr << "Вызов getStore до первого создания объекта!" << std::endl;
    }

    return m_store;
}

State Store::getState() {
    return m_state;
}

void Store::subscribe(Subscriber callback) {
    m_subscribers.push_back(callback);
}

void Store::dispatch(Action action) {
    m_state = m_reducer(m_state, action);

    for (const auto &sub : m_subscribers) {
        sub();
    }
}
