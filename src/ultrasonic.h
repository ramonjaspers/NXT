#include <vector>
//
// Created by brand on 4/6/2018.
//

#ifndef SRC_ULTRASONIC_H
#define SRC_ULTRASONIC_H

#include "BrickPi3.h"


class Ultrasonic {

private:
    // TODO: cast to 8 bit
    BrickPi3 Brick;
    uint8_t PORT;
    sensor_ultrasonic_t Sonic;
    float detected;
    std::vector <int> detection_range;

public:
    Ultrasonic(uint8_t port);
    bool object_in_range();
    void set_distance();
    int get_distance();
    ~Ultrasonic();

};


#endif //SRC_ULTRASONIC_H
