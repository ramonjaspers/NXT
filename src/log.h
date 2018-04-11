#ifndef LOG_H
#define LOG_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
//TODO: Doxygen generation

// ================================================== 
// ONLY DEV DEPENDENCY SHOULD BE REMOVED FROM RELEASE
// ==================================================



class Log {
private:
    std::ofstream debugFile;
public:
    Log();

/**
 *
 * @return
 */
    const std::string currentDateTime();
    void write_line(std::string ln);
    ~Log();

};

#endif // LOG_H
