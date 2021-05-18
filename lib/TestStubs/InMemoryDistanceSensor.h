//
// Created by Fedorov, Alex on 10/21/20.
//

#ifndef MARKIII_INMEMORYDISTANCESENSOR_H
#define MARKIII_INMEMORYDISTANCESENSOR_H


class InMemoryDistanceSensor {
    int distance = 0;
public:
    Inch getDistance();

    void setDistance(Inch distance);
};


#endif //MARKIII_INMEMORYDISTANCESENSOR_H
