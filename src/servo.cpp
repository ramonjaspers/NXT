#include "servo.h"
#include "BrickPi3.cpp" // for BrickPi3
#include <iostream>
#include <unistd.h>     // for usleep
#include <signal.h>     // for catching exit signals

using namespace std;

Servo::Servo(unsigned int PORT)
{
	BrickPi3 BP;
	this->PORT = PORT;
	this->PI = BP;
}

void Servo::set_speed(int power){
	this->PI.set_motor_power(this->PORT, power);
}
	
void Servo::halt(){
	this->PI.set_motor_power(this->PORT, 0);
}



Servo::~Servo()
{
}

