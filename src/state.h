#ifndef STATE_H
#define STATE_H

#include "init.h"
#include "motion.h"
#include "sensor.h"

//TODO: Doxygen generation

class State
{
private:
	Init init;
	Motion motion;
	Sensor sensor;

public:
	State();
	~State();
	void clear();
	bool obstacle_avoid();
	bool turn();
	bool grid_travel();

};

#endif // STATE_H
