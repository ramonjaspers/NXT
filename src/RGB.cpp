#include "RGB.h"
#include <vector>
#include <unistd.h>
#include <iostream>

/**
 *
 * @param port is the port corresponding to the brick-pi port
 */
RGB::RGB(uint8_t port){
	BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_COLOR_RED);
    sensor_color_t Color2;
    this->Color = Color2;
}


/**
 * returns if the detected color is within the range of the requested color
 * @param type_color is an int that contains 0 for white and 1 for black
 * @return
 */
bool RGB::in_range(unsigned int type_color){
	///this.reflected
	///return false;
    return (this->reflected_red >= this->range[0 + type_color] && this->reflected_red <= this->range[1 + type_color]);
}


/**
 * @return bool whether color is white or not
 */
bool RGB::is_white(){
	///return true;
    return this->in_range(0);
}

/**
 * @return bool whether color is black or not
 */
bool RGB::is_black(){
	///return false;
    return this->in_range(2);
}


void RGB::set_ranges() {

    /// TODO: dynamic ijken
    std::vector<int16_t> values;
    usleep(1*1000);
    for(unsigned int a=0; a<10; a++){
        values.push_back(this->get_current_value(true));
    }

    int16_t min_tmp = values[0];
    int16_t max_tmp = values[0];

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
/**
  * @return the minimum and maximum ranges for colors
 */
std::vector<int16_t> RGB::get_ranges(){
    return this->range;
}
/**
 * sets the current value to the current sensor data
 */
void RGB::set_current_value(){
    this->Brick.get_sensor(this->PORT, this->Color);
    this->reflected_red = this->Color.reflected_red;
}
/**
 *
 * @param rerun allow a new set to be run for receiving data from sensor
 * @return the found color value
 */
int RGB::get_current_value(bool rerun) {
    if (rerun) {
        this->set_current_value();
    }
    return this->reflected_red;
}


/// Constructor that will assign the color values after testing for values
RGB::RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max){

}


RGB::~RGB()
{
}

