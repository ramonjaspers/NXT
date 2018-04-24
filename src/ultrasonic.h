#ifndef SRC_ULTRASONIC_H
#define SRC_ULTRASONIC_H

#include <vector>


#include "BrickPi3.h"


class Ultrasonic {

private:
    // TODO: cast to 8 bit
    BrickPi3 Brick;
    int PORT;
    sensor_ultrasonic_t Sonic;
    float detected;
    std::vector <float> detection_range;

public:
    Ultrasonic();
    void set_port(const int port);
    Ultrasonic(const int port);
    bool object_in_range();
    float set_distance();
    float get_distance();
    ~Ultrasonic();
    int get_port();

};


#endif //SRC_ULTRASONIC_H
