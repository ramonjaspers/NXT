#ifndef INIT_H
#define INIT_H

#include "sensor.h"
#include "motion.h"


//TODO: Doxygen generation

class Init
{
private:
	Sensor sensor;
	Motion motion;
public:
	Init();
	~Init();
	Sensor get_sensor();
	Motion get_motion();
	
};

#endif // INIT_H
