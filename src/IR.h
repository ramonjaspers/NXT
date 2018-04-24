#ifndef IR_H
#define IR_H

#include <vector>
#include "BrickPi3.h"
//TODO: Doxygen generation

class IR
{
private:
    BrickPi3 Brick;
    uint8_t PORT;
    sensor_light_t Light;
	// index [0] and index[1] both contain the white colors min and max
	// index [2] and index[3] both contain the black colors min and max
	std::vector<int16_t> range;
	//bool run = false;

	// private variable that stores the detected value
	unsigned int detected;
public:
	IR(uint8_t port);
	IR();
	~IR();

    int get_port();

	void set_current_value();
	int get_current_value(bool rerun = false);
	bool in_range(unsigned int type_color);
	bool is_white();
	bool is_black();
	void set_port(const uint8_t port);
	void set_ranges() ;
	std::vector<int16_t> get_ranges();
};

#endif // IR_H
