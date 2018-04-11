#include <iostream>
#include "sensor.h"

#include "BrickPi3.h"
#include <unistd.h>
#include "IR.h"
#include "RGB.h"
#include "ultrasonic.h"




// initialize all the sensors
Sensor::Sensor(){
    IR ir;
    RGB rgb;
    Ultrasonic ultrasonic;

    std::cout << PORT_1 << std::endl;
    std::cout << PORT_2 << std::endl;
    std::cout << PORT_3 << std::endl;

    ir.set_port(PORT_1);
    rgb.set_port(PORT_2);
    ultrasonic.set_port(PORT_3);
    ultrasonic.set_port(PORT_3);
    std::cout << ir.get_port()<< std::endl;
    std::cout << ultrasonic.get_port() << std::endl;

    this->ir = ir;
    this->rgb = rgb;
    this->ultrasonic = ultrasonic;
}



// checking the ultrasonic sensor if something is withing X range of the device.
bool Sensor::object_near(){
    this->ultrasonic.set_distance();
    std::cout << this->ultrasonic.get_port() << std::endl;
    usleep(1000000 * 5);
   this->ultrasonic.set_distance();
    std::cout << this->ultrasonic.get_distance() << std::endl;

    return this->ultrasonic.object_in_range();
}

// requesting the sonic sensor to tell us how far away we are from an object.
int Sensor::get_distance_object(){
    return 100;
}

bool Sensor::both_black(){
    if(this->ir.is_white()){
        return false;
    }

    else if(this->rgb.is_white()){
        return false;
    }
    else if(this->ir.is_black() && this->rgb.is_black()){
        return true;
    } else{

        // exception should be thrown
        return true;
        // throw std::nested_exception( "Sensor data has an unexpected return, neither black nor white even though both black should be easy" );
    }

}
bool Sensor::both_white(){

    if(this->ir.is_black()){
        return false;
    }

    else if(this->rgb.is_black()){
        return false;
    }
    else if(this->ir.is_white() && this->rgb.is_white()){
        return true;
    } else{
        //  TODO: exception throw
        return true;
        // throw std::nested_exception ( "Sensor data has an unexpected return, neither black nor white even though white should be defined" );
    }

}

void Sensor::initializeIR(){
    // only the ranges are defined for now
    this->ir.set_ranges();
}

void Sensor::initializeRGB(){
    this->rgb.set_ranges();
}

void Sensor::initializeUS() {
    // Ultrasonic sensor doesn't actually do a lot, here for consistency sake a.t.m

}

bool Sensor::IR_black_RGB_white(){
    return (this->ir.is_black() && this->rgb.is_white());
}
bool Sensor::RGB_black_IR_white(){
    return (this->ir.is_white() && this->rgb.is_black());
}



// shutting down, resetting all brick pi i/o
Sensor::~Sensor()
{
}


