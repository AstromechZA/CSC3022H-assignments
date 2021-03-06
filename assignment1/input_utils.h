#ifndef INPUT_UTILS_H_
#define INPUT_UTILS_H_

#include <string>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>

namespace mrxben001
{

    int getIntFromCIN(int min, int max, char abortchar, int abortvalue);
    float getFloatFromCIN(int min, int max, char abortchar, int abortvalue);
    std::string getStringFromCIN();
    std::string getStringFromCIN(int minlength);

}

#endif 