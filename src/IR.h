#ifndef IR_H
#define IR_H

#include <vector>

//TODO: Doxygen generation

class IR
{
private:

	// index [0] and index[1] both contain the white colors min and max
	// index [2] and index[3] both contain the black colors min and max
	std::vector<int> range;
	//bool run = false;

	// private variable that stores the detected value
	unsigned int detected;
public:
	IR();
	~IR();
	void set_current_value();
	int get_current_value(bool rerun = false);
	bool in_range(unsigned int type_color);
	bool is_white();
	bool is_black();
	void set_ranges() ;
};

#endif // IR_H
