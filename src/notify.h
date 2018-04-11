#ifndef NOTIFY_H
#define NOTIFY_H

#include <string>

//TODO: Doxygen generation

class Notify
{
public:
	Notify();
	~Notify();
/**
 *
 * @param st
 * @param type
 * @return
 */
	std::string screen_render(std::string st, unsigned int type = 0);

};

#endif // NOTIFY_H
