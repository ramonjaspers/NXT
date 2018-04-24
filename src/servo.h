

#ifndef SERVO_H

#define SERVO_H

#include "BrickPi3.h" // for BrickPi3





//TODO: Doxygen generation



class Servo

{

private:

	BrickPi3 PI;

	unsigned int PORT;

public:

	Servo(uint8_t PORT);

	Servo();

	~Servo();

	void set_speed(int gradient);

	void set_port(uint8_t port);
    void motor_position(int degree);
	void halt();







};



#endif // SERVO_H
