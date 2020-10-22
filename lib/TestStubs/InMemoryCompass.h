//
// Created by Fedorov, Alex on 10/14/20.
//

#ifndef MARKIII_INMEMORYCOMPASS_H
#define MARKIII_INMEMORYCOMPASS_H

class InMemoryCompass {
    int currentDirection = 0;
public:
    explicit InMemoryCompass(int currentCourse);

    int getCurrentCourse() const;

    int direction() const;

    void setDirection(int newDirection);
};


#endif //MARKIII_INMEMORYCOMPASS_H
