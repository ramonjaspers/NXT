#include "log.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>

/// ======================================================
/// = ONLY DEV DEPENDENCY SHOULD BE REMOVED FROM RELEASE =
/// ======================================================

/// printing all the log data to a file for debugging purposes
Log::Log()
{
	this->debugFile.open("debug.txt");
	this->write_line("======= LOG START ========");
}

const std::string Log::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void Log::write_line(std::string ln){
	std::string temp_ln = currentDateTime() + " || " + ln;
	this->debugFile << temp_ln;
}
Log::~Log()
{
	this->debugFile.close();
}


