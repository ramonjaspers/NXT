#include "init.h"
#include "sensor.h"
#include "motion.h"
#include "log.h"

//TODO: Doxygen generation

// Initialise the sensors and initialise the wheels
Init::Init() {
    Sensor sn;
    Motion mt;
    this->sensor = sn;
    this->motion = mt;

    // polling color data
    // polling IR data
    // setting the sonic sensor position to default
    // polling the sonic sensor break range for an object
    // while loop to keep correcting the servo of the sonic sensor to ensure good orientation
}

/**
 *
 * @return
 */
Sensor Init::get_sensor() {
    return this->sensor;
}
/**
 *
 * @return
 */
Motion Init::get_motion() {
    return this->motion;
}


Init::~Init() {
}

