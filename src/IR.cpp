#include "IR.h"
#include <vector>
#include <iostream>
#include <algorithm>

IR::IR() {
    // initialize the port defaults
}

// define port number, struct naming

bool IR::in_range(unsigned int type_color = 0) {
    return (this->detected >= this->range[0 + type_color] && this->detected <= this->range[1 + type_color]);
}


bool IR::is_white() {
    return this->in_range(0);
}

void IR::set_current_value() {
    // refreshing the current value and acquiring a new one
    this->detected = 10;
}

int IR::get_current_value(bool rerun) {
    if (rerun) {
        this->set_current_value();
    }
    return this->detected;

}


bool IR::is_black() {
    return this->in_range(2);
}


void IR::set_ranges() {

    // while loop for 5 seconds? determine the appropriate time or perhaps using a limit amount of loops
    int p = 0;
    int l = 0;

    std::vector<int> min_max = {};
    while (l < 3) {
        std::vector<int> detected_values = {};
        while (p < 10) {
            //acquiring the value
            this->set_current_value();

            detected_values.push_back(this->get_current_value(true));

            p++;
        }

        // acquiring minimum and maximum values for the range
        signed int minimum_range = *std::min_element(detected_values.begin(), detected_values.end());
        signed int maximum_range = *std::max_element(detected_values.begin(), detected_values.end());
        std::cout << "run" << std::endl;
        min_max[0 + l] = minimum_range;
        min_max[1 + l] = maximum_range;
        l += 2;
    }

}


IR::~IR() {
}

