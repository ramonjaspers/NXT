#include "IR.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unistd.h>

IR::IR(uint8_t port) {
    BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_LIGHT_ON);
    sensor_light_t Light1;
    this->Light = Light1;

}

// define port number, struct naming

bool IR::in_range(unsigned int type_color = 0) {
    return (this->detected >= this->range[0 + type_color] && this->detected <= this->range[1 + type_color]);
}


bool IR::is_white() {
    return this->in_range(0);
}

void IR::set_current_value() {
    // refreshing the current value and acquiring a new one
    this->Brick.get_sensor(this->PORT, this->Light);
    //std::cout << this->Light.reflected << std::endl;
    this->detected = this->Light.reflected;
}

int IR::get_current_value(bool rerun) {
    if (rerun) {
        this->set_current_value();
    }
    return this->detected;
}


bool IR::is_black() {
    return this->in_range(2);
}


void IR::set_ranges() {

    // TODO: dynamic allocation
    std::vector<uint16_t> values;
    usleep(1*1000);
    for(unsigned int a=0; a<10; a++){
        values.push_back(this->get_current_value(true));
    }

    uint16_t min_tmp = values[0];
    uint16_t max_tmp = values[0];

    for(unsigned int i=1; i<values.size(); i++){
        std::cout << values[i] << std::endl;
        if(min_tmp >= values[i]){
            min_tmp = values[i];
        }
        if(max_tmp <= values[i]){
            max_tmp = values[i];
        }
    }
    this->range.push_back(min_tmp);
    this->range.push_back(max_tmp);
}
std::vector<uint16_t> IR::get_ranges(){
    return this->range;
}


IR::~IR() {
}

