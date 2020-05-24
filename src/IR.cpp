#include "IR.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unistd.h>

/**
 *
 * @param port is the port corresponding to the brick-pi port
 */
IR::IR(uint8_t port) {
    BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_LIGHT_ON);
    sensor_light_t Light1;
    this->Light = Light1;

}


/**
 * returns if the detected color is within the range of the requested color
 * @param type_color is an int that contains 0 for white and 1 for black
 * @return
 */
/////////////////////////////////////////////////////////////////////////
//// ... text ...
/////////////////////////////////////////////////////////////////////////
bool IR::in_range(unsigned int type_color = 0) {
    return (this->detected >= this->range[0 + type_color] && this->detected <= this->range[1 + type_color]);
}

/**
 * @return bool whether color is white or not
 */
bool IR::is_white() {
    return this->in_range(0);
}

/**
 * sets the current value to the current sensor data
 */
void IR::set_current_value() {
    /// refreshing the current value and acquiring a new one
    this->Brick.get_sensor(this->PORT, this->Light);
    ///std::cout << this->Light.reflected << std::endl;
    this->detected = this->Light.reflected;
}

/**
 *
 * @param rerun allow a new set to be run for receiving data from sensor
 * @return the found color value
 */
int IR::get_current_value(bool rerun) {
    if (rerun) {
        this->set_current_value();
    }
    return this->detected;
}

/**
 * @return bool whether color is black or not
 */
bool IR::is_black() {
    return this->in_range(2);
}

/**
 * Set's the default ranges of colors
 */
void IR::set_ranges() {

    /// TODO: dynamic allocation
    std::vector <uint16_t> values;
    usleep(1 * 1000);
    for (unsigned int a = 0; a < 10; a++) {
        values.push_back(this->get_current_value(true));
    }

    uint16_t min_tmp = values[0]; /// minimum value found from all the measurements
    uint16_t max_tmp = values[0]; /// maximum value found from all the measurements

    for (unsigned int i = 1; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
        if (min_tmp >= values[i]) {
            min_tmp = values[i];
        }
        if (max_tmp <= values[i]) {
            max_tmp = values[i];
        }
    }
    this->range.push_back(min_tmp); /// assigning to the ranges vector[0] min
    this->range.push_back(max_tmp); /// assigning to the ranges vector[1] max
}

/**
  * @return the minimum and maximum ranges for colors
 */
std::vector <uint16_t> IR::get_ranges() {
    return this->range;
}


IR::~IR() {
}

