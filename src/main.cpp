#include <stdio.h>
#include <iostream>
#include "state.h"
int main(int argc, char **argv)
{
	
	// new state object takes it all away
	State st;
	std::cout << st.turn() << std::endl;
	return 0;
}
