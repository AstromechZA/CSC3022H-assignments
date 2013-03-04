#ifndef INPUT_UTILS_H_
#define INPUT_UTILS_H_

#include <string>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>

namespace mrxben001
{

    int getIntFromCIN(int min, int max);
    float getFloatFromCIN(int min, int max, int bad);
    std::string getStringFromCIN();
    std::string getStringFromCIN(int minlength);

}

#endif 