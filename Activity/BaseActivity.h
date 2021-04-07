#ifndef CLOCK_BASEACTIVITY_H
#define CLOCK_BASEACTIVITY_H

#include <iostream>
#include <string>
#include <Store.h>
#include <globalTypes.h>

using std::string;


class BaseActivity {
public:
    virtual void start() = 0;

    virtual void render() = 0;
};


//// map activity
using MapActivity = map<IDActivity, BaseActivity *>;


#endif //CLOCK_BASEACTIVITY_H
