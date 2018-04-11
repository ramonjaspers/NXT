#include "servo.h"
#include "BrickPi3.h" // for BrickPi3
#include <iostream>
#include <unistd.h>     // for usleep
#include <signal.h>     // for catching exit signals

using namespace std;

Servo::Servo(uint8_t PORT)
{
	BrickPi3 BP;
	this->PORT = PORT;
	this->PI = BP;
}

Servo::Servo()
{
	BrickPi3 BP;
	this->PI = BP;
}

void Servo::set_speed(int power){
    std::cout << "power: " << power << ",  port: " << this->PORT << std::endl;
	this->PI.set_motor_power(this->PORT, power);
}

void Servo::set_port(const uint8_t port){
    this->PORT = port;
}


void Servo::halt(){
	this->PI.set_motor_power(this->PORT, 0);
}



Servo::~Servo()
{
}
