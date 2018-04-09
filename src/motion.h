#ifndef MOTION_H
#define MOTION_H
#include <vector>
#include "servo.h"
class Motion
{
private:

	int power;
  Servo right;
  Servo left;
  Servo top;


public:
	Motion(int speed);
	~Motion();
	void turn(char direction);
	void emergency_stop();
	void drive();
	void drive_reverse();
	void turn_reverse(char directie)
	

};

#endif // MOTION_H
