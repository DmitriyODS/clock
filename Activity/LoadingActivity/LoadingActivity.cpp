#include "LoadingActivity.h"

void LoadingActivity::start() {
    std::cout << "All good!" << std::endl;
}

void LoadingActivity::render() {

}

void LoadingActivity::_init() {

}

LoadingActivity::LoadingActivity() {
    _init();
}

LoadingActivity *LoadingActivity::createActivity() {
    static auto *loadingActivity = new LoadingActivity();

    return loadingActivity;
}
