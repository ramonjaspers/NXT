#ifndef STATE_H
#define STATE_H

#include "init.h"
#include "motion.h"
#include "sensor.h"
#include "log.h"
//TODO: Doxygen generation

class State
{
private:
	Init init;
	Log log;
	Motion motion;
	Sensor sensor;

public:
	State();
	~State();
	void clear();
	bool obstacle_avoid();
	bool turn();
	bool grid_travel();
	Motion getMotion();
	Sensor getSensor();

};

#endif // STATE_H
