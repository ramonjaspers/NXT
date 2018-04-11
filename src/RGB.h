#ifndef RGB_H
#define RGB_H

#include <vector>

//TODO: Doxygen generation

class RGB
{
	
// TODO: Update the header file
public:
	RGB();
	~RGB();
	/**
	 *
	 * @param type_color
	 * @return
	 */
	bool in_range(unsigned int type_color);
	/**
	 *
	 * @return
	 */
	bool is_white();
	/**
	 *
	 * @return
	 */
	bool is_black();
	/**
	 *
	 * @return
	 */
	std::vector<int> get_black_range() ;
	/**
	 *
	 * @return
	 */
	std::vector<int> get_white_range() ;
	/**
	 *
	 * @param white_min
	 * @param white_max
	 * @param black_min
	 * @param black_max
	 */
	RGB(unsigned int white_min,unsigned int white_max, unsigned int black_min, unsigned int black_max);

};

#endif // RGB_H
