#ifndef INIT_H
#define INIT_H

#include "sensor.h"
#include "motion.h"


//TODO: Doxygen generation
class Init {
private:
    Sensor sensor;
    Motion motion;
public:
    Init();
    ~Init();
/**
 *
 * @return
 */
    Sensor get_sensor();
/**
 *
 * @return
 */
    Motion get_motion();
};

#endif // INIT_H
