#include "ultrasonic.h"
#include <iostream>
#include <unistd.h>

Ultrasonic::Ultrasonic(const int port){
    BrickPi3 BP;
    this->Brick = BP;
    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_ULTRASONIC);
    sensor_ultrasonic_t Sonic3;
    this->Sonic = Sonic3;
}

Ultrasonic::Ultrasonic(){
    BrickPi3 BP;
    this->Brick = BP;
}


bool Ultrasonic::object_in_range(){
        // TODO: own detection
    return ( this->detected <= 50 );

}

float Ultrasonic::set_distance(){
    // code that extracts the range, stores it in detected
    //return this->detected;
    this->Brick.get_sensor(this->PORT, this->Sonic);
    this->detected = this->Sonic.cm;
    return this->detected;
}

void Ultrasonic::set_port(const int port){
    std::cout << "Poort in set port functie: " << port << std::endl;

    this->PORT = port;
    this->Brick.set_sensor_type(this->PORT, SENSOR_TYPE_NXT_ULTRASONIC);
    sensor_ultrasonic_t Sonic3;
    this->Sonic = Sonic3;

}

float Ultrasonic::get_distance(){
 this->set_distance();
 return this->detected;
}

int Ultrasonic::get_port(){
    return this->PORT;
}

Ultrasonic::~Ultrasonic(){

}
