#include <vector>
//
// Created by brand on 4/6/2018.
//

#ifndef SRC_ULTRASONIC_H
#define SRC_ULTRASONIC_H

//TODO: Doxygen generation

class Ultrasonic {
private:
    // TODO: cast to 8 bit
    unsigned int detected;

    std::vector <int> detection_range;



public:
    Ultrasonic();
    /**
     *
     * @return
     */
    bool object_in_range();
    void get_distance();
    ~Ultrasonic();

};


#endif //SRC_ULTRASONIC_H
