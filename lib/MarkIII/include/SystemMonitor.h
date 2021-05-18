//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_SYSTEMMONITOR_H
#define MARKIII_SYSTEMMONITOR_H

#include <SystemState.h>

template<typename Display, typename Compass, typename Timer, typename DistanceSensor>
class SystemMonitor {
    Display &display;
    Compass &compass;
    Timer &timer;
    DistanceSensor &distanceSensor;
public:
    SystemMonitor(Display &display, Compass &compass, Timer &timer, DistanceSensor &distanceSensor)
            : display(display), compass(compass), timer(timer), distanceSensor(distanceSensor) {}

    void init() {}

    void process() {
        if (timer.isReady()) {
            SystemState systemState{distanceSensor.getDistance(), compass.direction()};
            display.showState(systemState);
        }
    };
};


#endif //MARKIII_SYSTEMMONITOR_H
