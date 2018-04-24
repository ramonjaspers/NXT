#ifndef RGB_H
#define RGB_H

#include <vector>
#include "BrickPi3.h"
//TODO: Doxygen generation

class RGB
{
private:
    BrickPi3 Brick;
    uint8_t PORT;
    sensor_color_t Color;
	// index [0] and index[1] both contain the white colors min and max
	// index [2] and index[3] both contain the black colors min and max
	std::vector<int16_t> range;
	//bool run = false;

	// private variable that stores the detected value
	unsigned int reflected_red;
// TODO: Update the header file
public:
	RGB(uint8_t port);
	RGB();
	void set_port(uint8_t port);
	~RGB();
	bool in_range(unsigned int type_color);
	bool is_white();
	bool is_black();
	void set_current_value();
	int get_current_value(bool rerun = false);
	std::vector<int> get_black_range() ;
	std::vector<int> get_white_range() ;
	std::vector<int16_t> get_ranges();
	void set_ranges();
	RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max);



};

#endif // RGB_H
