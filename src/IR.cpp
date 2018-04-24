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

IR::IR(){
    BrickPi3 BP;
    this->Brick = BP;
}

int IR::get_port(){
    std::cout << this->PORT << std::endl;
    return this->PORT;
}

void IR::set_port(const uint8_t port){
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_LIGHT_ON);
    sensor_light_t Light1;
    std::cout << "Poort in IR set functie: " << int(this->PORT) << '\n';
    this->Light = Light1;
}

// define port number, struct naming

bool IR::in_range(unsigned int type_color = 0) {

    return (this->Light.reflected >= this->range[0 + type_color] && this->Light.reflected < this->range[1 + type_color]);
    //return true;
}


bool IR::is_white() {
    std::cout << this->in_range(0);
    return true;
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
    return this->in_range(0);
}


void IR::set_ranges() {
    std::cout << "IJKEN" << std::endl;
    std::vector<int16_t> values;
    usleep(1*1000);
    for(unsigned int a=0; a<10; a++){
        values.push_back(this->get_current_value(true));
    }

    int16_t min_tmp = values[0];
    int16_t max_tmp = values[0];

    for(unsigned int i=1; i<values.size(); i++){
        if(min_tmp >= values[i]){
            min_tmp = values[i];
        }
        if(max_tmp <= values[i]){
            max_tmp = values[i];
        }
    }
    this->range.push_back(min_tmp - 100);
    this->range.push_back(max_tmp + 100);
    std::cout << "GEIJKT        " << std::endl;
    usleep(5*1000000);
}
std::vector<int16_t> IR::get_ranges(){
    return this->range;
}


IR::~IR() {
}

