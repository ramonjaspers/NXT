#include "motion.h"
#include "servo.h"
#include <vector>
#include "BrickPi3.h"
#include <unistd.h>
#include <iostream>



Motion::Motion(int speed)
{
	// initializing the servo configuration, passing by reference ideally for vector

    Servo servo_right;
    servo_right.set_port(PORT_B);
    Servo servo_left;
    servo_left.set_port(PORT_C);
    Servo servo_sensor;
    servo_sensor.set_port(PORT_D);

    this->speed = speed;

    this->right = servo_right;
    this->left  = servo_left;
    this->top   = servo_sensor;

}


void Motion::turn(char directie){
	// decreasing the left increasing the right and in reverse
	if(directie == 'r') {
		for(unsigned int i = 0; i < (3 * (this->speed / 10)); i += (this->speed / 10)) {
			this->left.set_speed(this->speed + i);
			this->right.set_speed(this->speed - i);
			usleep(20000);
		}
	} else {
		for(unsigned int i = 0; i < (3 * (this->speed / 10)); i += (this->speed / 10)) {
			left.set_speed(this->speed - i);
			right.set_speed(this->speed + i);
			usleep(20000);
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
	std::cout << this->speed;
	left.set_speed(this->speed);
	right.set_speed(this->speed);
}

void Motion::drive_reverse(){
	left.set_speed(-this->speed);
	right.set_speed(-this->speed);
}

void Motion::turn_reverse(char directie){
	// decreasing the left increasing the right and in reverse
	if(directie == 'l') {
		for(unsigned int i = 0; i < (3 * (-this->speed / 10)); i -= (-this->speed / 10)) {
			left.set_speed(-this->speed + i);
			right.set_speed(-this->speed - i);
			usleep(20000);
		}
	} else if(directie == 'r') {
		for(unsigned int i = 0; i < (3 * (-this->speed / 10)); i -= (-this->speed / 10)) {
			left.set_speed(-this->speed - i);
			right.set_speed(-this->speed + i);
			usleep(20000);
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


