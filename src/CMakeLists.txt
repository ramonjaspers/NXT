cmake_minimum_required(VERSION 3.9)
project(src)

set(CMAKE_CXX_STANDARD 11)

add_executable(src
        BrickPi3.cpp
        BrickPi3.h
        init.cpp
        init.h
        IR.cpp
        IR.h
        log.cpp
        log.h
        main.cpp
        motion.cpp
        motion.h
        notify.cpp
        notify.h
        RGB.cpp
        RGB.h
        sensor.cpp
        sensor.h
        servo.cpp
        servo.h
        state.cpp
        state.h
        ultrasonic.cpp
        ultrasonic.h
        )
