#include "RGB.h"
#include <vector>

//TODO: Doxygen generation


// constructor that is used for initialising the sensor, should only return polling data for 10 seconds.
RGB::RGB()
{
	
	
	
}


// TODO: Calculate if a color is in a certain range by brick-pi interface
/**
 *
 * @param type_color
 * @return
 */
bool RGB::in_range(unsigned int type_color){
	//this.reflected
	return false;
}



// TODO: Assign to brick-pi interface
/**
 *
 * @return
 */
bool RGB::is_white(){
	return true;
}


// TODO: Assign to brick-pi interface
/**
 *
 * @return
 */
bool RGB::is_black(){
	return false;
}


// TODO: Assign to brick-pi interface
/**
 *
 * @return
 */
std::vector<int> RGB::get_black_range() {
	std::vector<int> v = {};
	return v;
}


// TODO: Assign to brick-pi interface
/**
 *
 * @return
 */
std::vector<int> RGB::get_white_range() {
	std::vector<int> v = {};
	return v;
}



// Constructor that will assign the color values after testing for values
/**
 *
 * @param white_min
 * @param white_max
 * @param black_min
 * @param black_max
 */
RGB::RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max){

}


RGB::~RGB()
{
}

