#ifndef IR_H
#define IR_H

#include <vector>

//TODO: Doxygen generation

class IR
{
public:
	IR();
	~IR();
	
	bool in_range(unsigned int type_color);
	bool is_white();
	bool is_black();
	std::vector <int> get_black_range() ;
	std::vector <int> get_white_range() ;
};

#endif // IR_H
