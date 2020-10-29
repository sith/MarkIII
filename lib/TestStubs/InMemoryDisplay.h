//
// Created by Fedorov, Alex on 10/28/20.
//

#ifndef MARKIII_INMEMORYDISPLAY_H
#define MARKIII_INMEMORYDISPLAY_H


class InMemoryDisplay {
  unsigned  int printedDistance = 0;
    bool printedMotorIsRunningState = false;
public:

    unsigned int getPrintedDistance() const;

    void showDistanceToObstacle(unsigned int distance);

    void showMotorState(bool motorIsMoving);

    bool registeredMotorState() const;
};


#endif //MARKIII_INMEMORYDISPLAY_H
