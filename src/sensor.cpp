#include "sensor.h"
#include "IR.h"
#include "RGB.h"
//#include "ultrasonic.h"





// initialize all the sensors 
Sensor::Sensor()
{
}


// checking the ultrasonic sensor if something is withing X range of the device.
bool Sensor::object_near(){
	return false;
}

// requesting the sonic sensor to tell us how far away we are from an object.
int Sensor::get_distance_object(){
	return 100;
}

bool Sensor::both_black(){
	return true;
}
bool Sensor::both_white(){
	return false;
}

// shutting down, resetting all brick pi i/o
Sensor::~Sensor()
{
}

