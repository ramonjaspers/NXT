#ifndef SRC_ULTRASONIC_H
#define SRC_ULTRASONIC_H

#include <vector>


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
    Ultrasonic();
    int set_port(uint8_t port);
    Ultrasonic(const uint8_t port);
    bool object_in_range();
    void set_distance();
    int get_distance();
    ~Ultrasonic();
    uint8_t get_port();

};


#endif //SRC_ULTRASONIC_H
