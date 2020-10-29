//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_SYSTEMMONITOR_H
#define MARKIII_SYSTEMMONITOR_H

template<typename Display, typename Compass, typename Timer, typename Motor, typename DistanceSensor>
class SystemMonitor {
    Display &display;
    Compass &compass;
    Timer &timer;
    Motor &motor;
    DistanceSensor &distanceSensor;
public:
    SystemMonitor(Display &display, Compass &compass, Timer &timer, Motor &motor, DistanceSensor &distanceSensor)
            : display(display), compass(compass), timer(timer), motor(motor), distanceSensor(distanceSensor) {}

    void init() {}

    void process() {
        if (timer.isReady()) {
            display.showDistanceToObstacle(distanceSensor.getDistance());
            display.showMotorState(motor.isRunning());
        }
    };
};


#endif //MARKIII_SYSTEMMONITOR_H
