#ifndef NOTIFY_H
#define NOTIFY_H

#include <string>

///TODO: Doxygen generation

class Notify
{
public:
	Notify();
	~Notify();
	std::string screen_render(std::string st, unsigned int type = 0);

};

#endif /// NOTIFY_H
