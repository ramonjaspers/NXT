#ifndef MOTION_H
#define MOTION_H

#include <vector>
#include "servo.h"
//TODO: Doxygen generation

class Motion {

private:

    Servo up;
    Servo left;
    Servo right;
public:

    Motion();

/**
 *
 * @param left
 * @param right
 */
    Motion(unsigned int left, unsigned int right);
    ~Motion();
/**
 *
 * @param left
 * @param right
 */
    void turn(unsigned int left, unsigned int right);
    void emergency_stop();
    void default_speed();

};

#endif // MOTION_H
