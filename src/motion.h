#ifndef MOTION_H
#define MOTION_H
#include <vector>
class Motion
{
private:
	unsigned int left;
	unsigned int right;
public:
	Motion();
	Motion(unsigned int left, unsigned int right);
	~Motion();
	void turn(unsigned int left, unsigned int right);
	void emergency_stop();
	void default_speed();

};

#endif // MOTION_H
