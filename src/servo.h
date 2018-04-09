#ifndef SERVO_H
#define SERVO_H
#include "BrickPi3.cpp" // for BrickPi3


//TODO: Doxygen generation

class Servo
{
private:
	BrickPi3 PI;
	unsigned int PORT;
public:
	Servo(unsigned int PORT);
	~Servo();
	void set_speed(int gradient);
	void execute_speed(int speed);
	void halt();



};

#endif // SERVO_H
