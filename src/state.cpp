#include "state.h"
#include "motion.h"
#include "log.h"
#include "sensor.h"
#include "init.h"
#include <iostream>

// The different types of states are 
State::State()
{	
	Log log;
	Init it;
	
	this->init = it;
	
	this->motion = this->init.get_motion();
	this->sensor = this->init.get_sensor();
}

Motion State::getMotion(){
	return this->motion;
}

Sensor State::getSensor(){
	return this->sensor;
}

// Driving straight, everything is going good
void State::clear(){
	
	// sensor data scanning the surrounding and driving straight
}



// Driving slower and the ultrasonic sensor needs to be in 'avoid', 'check if I'm past' mode etc
bool State::obstacle_avoid(){
	return true;
}

// Driving slower and taking a turn
bool State::turn(){
	return true;
}

// driving through a grid storing the directions driven.
bool State::grid_travel(){
	return true;
}

State::~State()
{
}

