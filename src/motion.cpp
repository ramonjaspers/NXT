#include "motion.h"
#include "servo.h"
#include <vector>



Motion::Motion(int speed){
	// initializing the servo configuration, passing by reference ideally for vector
    Servo servo_right;
    Servo servo_left;
    Servo servo_sensor;
	
	  this->power = speed;

	  this->right = servo_right;
    this->left  = servo_left;
    this->top   = servo_sensor;
}


void Motion::turn(char directie){
	// decreasing the left increasing the right and in reverse
	if(directie == 'r') {
		for(unsigned int i = 0; i < (3 * (speed / 10)); i += (speed / 10)) {
			left.set_speed(speed + i);
			right.set_speed(speed - i);
		}
	} else {
		for(unsigned int i = 0; i < (3 * (speed / 10)); i += (speed / 10)) {
			left.set_speed(speed - i);
			right.set_speed(speed + i);
		}
	}
	// logging if left > right -> going left
	// logging if right > left -> going right
	
}

void Motion::emergency_stop(){
	left.halt();
	right.halt();
}

void Motion::drive(){
	// setting both motion values the drive straight on
	left.set_speed(speed);
	right.set_speed(speed);
}

void Motion::drive_reverse(){
	left.set_speed(-speed);
	right.set_speed(-speed);
}

void Motion::turn_reverse(char directie){
	// decreasing the left increasing the right and in reverse
	if(directie == 'l') {
		for(unsigned int i = 0; i < (3 * (-speed / 10)); i -= (-speed / 10)) {
			left.set_speed(-speed + i);
			right.set_speed(-speed - i);
		}
	} else if(directie == 'r') {
		for(unsigned int i = 0; i < (3 * (-speed / 10)); i -= (-speed / 10)) {
			left.set_speed(-speed - i);
			right.set_speed(-speed + i);
		}
	}
	else{
		std::cout << "Geen gelding karakter opgegeven.";
	}
	// logging if left > right -> going left
	// logging if right > left -> going right
}

Motion::~Motion()
{
}


