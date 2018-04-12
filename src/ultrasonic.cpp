#include "ultrasonic.h"
#include <iostream>
#include <unistd.h>

Ultrasonic::Ultrasonic(uint8_t port) {
    BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_ULTRASONIC);
    sensor_ultrasonic_t Sonic3;
    this->Sonic = Sonic3;
}

/**
 * @return bool if the value is below the expected range
 */
bool Ultrasonic::object_in_range() {
    return (this->detected <= 50);
}

/**
 * acquires sensor data and stores in member variable
 */
void Ultrasonic::set_distance() {
    // code that extracts the range, stores it in detected
    //return this->detected;
    this->Brick.get_sensor(this->PORT, this->Sonic);
    this->detected = this->Sonic.cm;
    std::cout << this->Sonic.cm << std::endl;
}

/**
 * @return sensor value
 */
int Ultrasonic::get_distance() {
    return this->detected;
}

Ultrasonic::~Ultrasonic() {

}
