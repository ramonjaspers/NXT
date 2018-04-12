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
 * @return motion object that contains the control of the servo's
 */
Motion State::getMotion() {
    return this->motion;
}

/**
 *
 * @return sensor object that contains the control of the RGB, IR and Ultrasonic
 */
Sensor State::getSensor() {
    return this->sensor;
}

/**
 * When the system is proceeding as expected
 */
void State::clear() {
    if (!this->sensor.both_white() && !this->sensor.object_near()) {
        this->object_or_turn();
    }

    // TODO: default motion
    this->motion.default_speed();
}

/**
 * Decides whether or not the turns should be made or if the obstacle avoid run needs to be made
 */
void State::object_or_turn() {
    if (this->sensor.both_white()) {
        this->obstacle_avoid();
    } else if (!this->sensor.object_near()) {
        this->turn();
    }
}

/**
 * Function that will try to run around an obstacle
 * @return if the obstacle has been avoided
 */
bool State::obstacle_avoid() {
    int STATE = 1;
    while (STATE != 8) {
        switch (STATE) {
            case 1:
                cout << "STATE 1" << endl;
                if (detect(Sonic3)) {
                    STATE = 2;
                    break;
                }
            case 2:
                turn(45); //45 naar graden rechts
                SForwards();
                cout << "STATE 2" << endl;
                STATE = 3;
            case 3:
                usleep(1.5 * 1000000);
                cout << "STATE 3" << endl;
                turn(-45);
                SForwards();
                STATE = 4;

            case 4:
                cout << "STATE 4" << endl;
                sensorTurn(-90);
                STATE = 5;


            case 5:
                cout << "STATE 5" << endl;
                if (detect(Sonic3)) {
                    this->clear();
                } else {
                    STATE = 6;
                }

            case 6:
                usleep(1.5 * 1000000);
                cout << "STATE 6" << endl;
                turn(-50); //50  graden naar links
                SForwards();
                STATE = 7;

            case 7:
                usleep(0.5 * 1000000);
                cout << "STATE 7" << endl;
                sensorTurn(0);
                STATE = 8;
        }
        return true;
    }
}

// Driving slower and taking a turn
    void State::turn() {
        // IR Left
        // RGB Right

        while (!this->sensor.both_white()) {
            if (this->sensor.object_near()) {
                obstacle_avoid();
            } else if (this->sensor.IR_black_RGB_white()) {
                this->motion.turn('l');
            } else if (this->sensor.RGB_black_IR_white()) {
                this->motion.turn('r');
            }
        }
    }

// driving through a grid storing the directions driven.
    bool State::grid_travel() {
        return true;
    }

    State::~State() {
    }

