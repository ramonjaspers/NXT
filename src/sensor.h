#ifndef SENSOR_H
#define SENSOR_H

#include "IR.h"
#include "RGB.h"
#include "ultrasonic.h"


//TODO: Doxygen generation

class Sensor
{

private:
    IR ir;
    RGB rgb;
    Ultrasonic ultrasonic;

// TODO: Update the header file
public:
    Sensor();
    /**
     *
     * @param PORT_IR
     * @param PORT_RGB
     * @param PORT_US
     */
    Sensor(const unsigned int PORT_IR, const unsigned int PORT_RGB, const unsigned int PORT_US );
    ~Sensor();
    /**
     *
     * @return
     */
    bool object_near();
    /**
     *
     * @return
     */
    int get_distance_object();
    /**
     *
     * @return
     */
    bool both_black();
    /**
     *
     * @return
     */
    bool both_white();

    /**
     *
     * @return
     */
    bool IR_black_RGB_white();
    /**
     *
     * @return
     */
    bool RGB_black_IR_white();

    void initializeIR();
    void initializeRGB();
    void initializeUS();
};

#endif // SENSOR_H
