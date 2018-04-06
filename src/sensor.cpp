#include "sensor.h"
#include "IR.h"
#include "RGB.h"
#include "ultrasonic.h"




// initialize all the sensors 
Sensor::Sensor()
{
}

Sensor::Sensor(const unsigned int PORT_IR, const unsigned int PORT_RGB, const unsigned int PORT_US ){
	
	IR ir;
	RGB rgb;
	Ultrasonic ultrasonic;
	// Ultrasonic us;
	
	this->ir = ir;
	this->rgb = rgb;
    this->ultrasonic = ultrasonic;
	
	
	
	
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
	if(true == this->ir.is_white()){
		return false;
	} 
	
	else if(true == this->rgb.is_white()){
		return false;
	}
	else if(true == this->ir.is_black() && true == this->rgb.is_black()){
		return true;
	} else{
		
		// exception should be thrown
		return true;
		// throw std::nested_exception( "Sensor data has an unexpected return, neither black nor white even though both black should be easy" );
	}

}
bool Sensor::both_white(){
	
	if(true == this->ir.is_black()){
		return false;
	} 
	
	else if(true == this->rgb.is_black()){
		return false;
	}
	else if(true == this->ir.is_white() && true == this->rgb.is_white()){
		return true;
	} else{
		// exception thrown
		return true;
		// throw std::nested_exception ( "Sensor data has an unexpected return, neither black nor white even though white should be defined" );
	}

}

// shutting down, resetting all brick pi i/o
Sensor::~Sensor()
{
}

