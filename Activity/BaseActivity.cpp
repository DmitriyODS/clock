#include "BaseActivity.h"

void BaseActivity::_preparingActivity() {
    // TODO: здесь делаем какую - то настройку активности
}

void BaseActivity::_init() {
    m_is_running = true;

    _initWindow();

    _initComponents();

    _initThreadRender();

    _preparingActivity();
}

void BaseActivity::_initWindow() {
    m_window = new RenderWindow(m_video_mode, m_title_window, m_style_window);

    m_window->setVerticalSyncEnabled(true);

    m_window->setActive(false);
}

void BaseActivity::_initComponents() {
    // TODO: здесь выполняем инициализацию компонентов в активности
}

void BaseActivity::_initThreadRender() {
    // TODO: здесь создаём поток отрисовки

    m_thread_render = new Thread(&BaseActivity::render, this);
}

void BaseActivity::_reinitWindow() {
    // TODO: что - то для переоткрытия
}

void BaseActivity::_createIntent() {
    // TODO: прописываем работу с intent-ом
}


BaseActivity::BaseActivity(Activity id_activity, string title, VideoMode video_mode, Uint32 style_window)
        : m_title_window(title), m_video_mode(video_mode),
          m_store(Store::getStore()), m_style_window(style_window), m_id_activity(id_activity) {
    // TODO: Можно что - то ещё инициализировать при создании
    //  объекта
}

void BaseActivity::start() {
    _init();

    m_thread_render->launch();

    while (m_is_running) {

        Event event{};

        if (m_store->getState().app_state.m_exit) {
            m_is_running = false;
        }

        while (m_window->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed: {
                    m_is_running = false;
                    break;
                }
                case Event::MouseMoved: {
                    selectComponent(event.mouseMove);
                    break;
                }
                case Event::MouseButtonPressed: {
                    clickComponent(event.mouseButton.button);
                    break;
                }
            }
        }

    }

    m_window->close();

    _createIntent();
}

void BaseActivity::render() {
    m_window->setActive(true);

    m_color_app = m_store->getState().app_state.color_app;

    while (m_window->isOpen()) {
        m_window->clear(m_color_app.background);

        for (auto item : m_components) {
            item->render(m_window);
        }

        m_window->display();
    }
}

BaseActivity::~BaseActivity() {
    m_thread_render->wait();

    delete m_thread_render;

    delete m_window;

    for (auto *pItem : m_components) {
        delete pItem;
    }
}

void BaseActivity::selectComponent(Event::MouseMoveEvent mouse_move) {
    BaseComponent *cmpnt{};

    for (auto &item : m_components) {
        cmpnt = item->select(mouse_move);

        if (cmpnt) break;
    }

    m_store->dispatch(setSelectComponent(cmpnt));
}

void BaseActivity::clickComponent(Mouse::Button button) {
    BaseComponent *component = static_cast<BaseComponent *>(m_store->getState().app_state.select_component);

    if (component) {
        component->click();
    }
}

Activity BaseActivity::getId() {
    return m_id_activity;
}
