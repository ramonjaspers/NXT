#ifndef SENSOR_H
#define SENSOR_H

#include "IR.h"
#include "RGB.h"
//#include "ultrasonic.h"


//TODO: Doxygen generation

class Sensor
{
	
// TODO: Update the header file
public:
	Sensor();
	~Sensor();
	bool object_near();
	int get_distance_object();
	bool both_black();
	bool both_white();
};

#endif // SENSOR_H
