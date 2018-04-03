#ifndef RGB_H
#define RGB_H

#include <vector>

//TODO: Doxygen generation

class RGB
{
	
// TODO: Update the header file
public:
	RGB();
	~RGB();
	bool in_range(unsigned int type_color);
	bool is_white();
	bool is_black();
	std::vector<int> get_black_range() ;
	std::vector<int> get_white_range() ;
	RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max);
	


};

#endif // RGB_H
