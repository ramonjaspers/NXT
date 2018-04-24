#include "RGB.h"
#include <vector>
#include <unistd.h>
#include <iostream>


// constructor that is used for initialising the sensor, should only return polling data for 10 seconds.
RGB::RGB(uint8_t port){
	BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_COLOR_RED);
    sensor_color_t Color2;
    this->Color = Color2;
}

RGB::RGB(){
	BrickPi3 BP;
    this->Brick = BP;
}

void RGB::set_port(uint8_t port){
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_COLOR_RED);
    sensor_color_t Color2;
    this->Color = Color2;
}


// TODO: Calculate if a color is in a certain range by brick-pi interface
bool RGB::in_range(unsigned int type_color){
	//this.reflected
	//return false;
    return (this->reflected_red >= this->range[0 + type_color] && this->reflected_red < this->range[1 + type_color]);
}



// TODO: Assign to brick-pi interface
bool RGB::is_white(){
	//return true;
    return this->in_range(0);
}


// TODO: Assign to brick-pi interface
bool RGB::is_black(){
	//return false;
    return this->in_range(0);
}


// TODO: Assign to brick-pi interface
std::vector<int> RGB::get_black_range() {
	std::vector<int> v = {};
	return v;
}


// TODO: Assign to brick-pi interface
std::vector<int> RGB::get_white_range() {
	std::vector<int> v = {};
	return v;
}

void RGB::set_ranges() {
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

std::vector<int16_t> RGB::get_ranges(){
    return this->range;
}

void RGB::set_current_value(){
    this->Brick.get_sensor(this->PORT, this->Color);
    this->reflected_red = this->Color.reflected_red;
}

int RGB::get_current_value(bool rerun) {
    if (rerun) {
        this->set_current_value();
    }
    return this->reflected_red;
}


// Constructor that will assign the color values after testing for values
RGB::RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max){

}


RGB::~RGB()
{
}

