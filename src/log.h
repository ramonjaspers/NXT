#ifndef LOG_H
#define LOG_H

#include <string>


//TODO: Doxygen generation

// ================================================== 
// ONLY DEV DEPENDENCY SHOULD BE REMOVED FROM RELEASE
// ==================================================



class Log
{
public:
	Log();
	write(std::string ln);
	~Log();

};

#endif // LOG_H
