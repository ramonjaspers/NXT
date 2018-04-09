#ifndef MOTION_H
#define MOTION_H
#include <vector>
#include "servo.h"
class Motion
{
private:
	Servo up;
	Servo left;
	Servo right;
public:
	Motion();
	Motion(unsigned int left, unsigned int right);
	~Motion();
	void turn(unsigned int left, unsigned int right);
	void emergency_stop();
	void default_speed();

};

#endif // MOTION_H
