#include "state.h"
#include "motion.h"
#include "log.h"
#include "sensor.h"
#include "init.h"
#include <iostream>

// The different types of states are 
State::State() {
    Log log;
    Init it;

    this->init = it;

    this->motion = this->init.get_motion();
    this->sensor = this->init.get_sensor();
}

/**
 *
 * @return
 */
Motion State::getMotion() {
    return this->motion;
}

/**
 *
 * @return
 */
Sensor State::getSensor() {
    return this->sensor;
}

// Driving straight, everything is going good
void State::clear() {
    if (!this->sensor.both_white() && !this->sensor.object_near()) {
        object_or_turn();
    }

    // TODO: default motion
    this->motion.default_speed();
}

void State::object_or_turn() {
    if (this->sensor.both_white()) {
        obstacle_avoid();
    } else if (!this->sensor.object_near()) {
        turn();
    }
}

// Driving slower and the ultrasonic sensor needs to be in 'avoid', 'check if I'm past' mode etc
/**
 *
 * @return
 */
bool State::obstacle_avoid() {
    return true;
}

// Driving slower and taking a turn
void State::turn() {
    // IR Left
    // RGB Right

    while (!this->sensor.both_white()) {
        if (this->sensor.object_near()) {
            obstacle_avoid();
        } else if (this->sensor.IR_black_RGB_white()) {
            //TODO: turn left
        } else if (this->sensor.RGB_black_IR_white()) {
            //TODO: Turn right
        }
    }

}

// driving through a grid storing the directions driven.
/**
 *
 * @return
 */
bool State::grid_travel() {
    return true;
}

State::~State() {
}

