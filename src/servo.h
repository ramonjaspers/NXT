#ifndef SERVO_H
#define SERVO_H


//TODO: Doxygen generation

class Servo
{
public:
	Servo();
	~Servo();


	void set_speed(int gradient);
	void execute_speed(int speed);
	void halt();


	
};

#endif // SERVO_H
