//
// Created by brand on 4/6/2018.
//

#include "ultrasonic.h"
//TODO: Doxygen generation


Ultrasonic::Ultrasonic(){

}

/**
 *
 * @return
 */
bool Ultrasonic::object_in_range(){

    return ( this->detected >= this->detection_range[0] && this->detected <= this->detection_range[1] );

}
/**
 *
 */
void Ultrasonic::get_distance(){

    // code that extracts the range, stores it in detected
    //return this->detected;
}

Ultrasonic::~Ultrasonic(){

}