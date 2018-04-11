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
	/**
	 *
	 * @return
	 */
	bool obstacle_avoid();
	void turn();
	/**
	 *
	 * @return
	 */
	bool grid_travel();
	void object_or_turn();
	/**
	 *
	 * @return
	 */
	Motion getMotion();
	/**
	 *
	 * @return
	 */
	Sensor getSensor();

};

#endif // STATE_H
