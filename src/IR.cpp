#include "IR.h"
#include <vector>

IR::IR()
{
	
	// initialize the port defaults
}

// define port number, struct naming

// TODO: Calculate if a color is in a certain range by brick-pi interface
bool IR::in_range(unsigned int type_color){
	return false;
}



// TODO: Assign to brick-pi interface
bool IR::is_white(){
	return true;
}


// TODO: Assign to brick-pi interface
bool IR::is_black(){
	return false;
}


// TODO: Assign to brick-pi interface
std::vector<int> IR::get_black_range() {
	std::vector<int> v = {};
	return v;
}


// TODO: Assign to brick-pi interface
std::vector<int> IR::get_white_range() {
	std::vector<int> v = {};
	return v;
}



IR::~IR()
{
}

