#include "motion.h"
#include "servo.h"
#include <vector>


Motion::Motion(){
	// initializing the servo configuration, passing by reference ideally for vector
    Servo up;
    Servo left;
    Servo right;

	this->right = right;
    this->left  = left;
    this->up    = up;
}


void Motion::turn(unsigned int left, unsigned int right){
	// decreasing the left increasing the right
	// logging if left > right -> going left
	// logging if right > left -> going right
	
}

void Motion::emergency_stop(){
	// decreasing all motion values to 0
	//for(unsigned int k)
}

void Motion::default_speed(){
	// setting both motion values the drive straight on
}

Motion::~Motion()
{
}

