#include "init.h"
#include "sensor.h"
#include "motion.h"
#include "log.h"

/// Initialise the sensors and initialise the wheels
/*
 * Initializes the sensors and motion class
 *
 */
Init::Init() {
    Sensor sn;
    Motion mt;
    this->sensor = sn;
    this->motion = mt;
}

/**
 *
 * @return a configured sensor that has done default ranging
 */
Sensor Init::get_sensor() {
    return this->sensor;
}

/**
 *
 * @return a configured motion object that has servos ready to rumble
 */
Motion Init::get_motion() {
    return this->motion;
}


Init::~Init() {
}

