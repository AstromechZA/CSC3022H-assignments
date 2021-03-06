#include "input_utils.h"

namespace mrxben001
{

    /*
    int getIntFromCIN(int min, int max)
    Nice safe method to get a menu selection from the std::cin.
    This method checks for safe values and returns any integer within the required range. If input
    is out of range or invalid, this will print appropriate messages and prompt for more input. The 'q'
    quit character is also supported and is returned as -1.
    */
    int getIntFromCIN(int min, int max, char abortchar, int abortvalue)
    {
        std::string input = "";
        char inputchar = abortchar;
        int output;
        while (true)
        {
            std::getline(std::cin, input);
            std::stringstream mystream(input);
            if (mystream >> output)
            {
                if((output <= max) && (output >= min)) return output;
                std::cout << "Option out of range (" << min << "-" << max << "), try again :" << std::endl;
            }
            else
            {
                // clear bad read flags, so we can read the same input again
                mystream.clear();  
                if((mystream >> inputchar) && (inputchar == abortchar)) return abortvalue;
                std::cout << "Invalid input, try again :" << std::endl;
            } 
            
        }
    }

    /*
    float getFloatFromCIN(int min, int max, char abortchar, int abortvalue)
    Get a float value from std::cin
    Allow abort and ensure valid return value.
    */
    float getFloatFromCIN(int min, int max, char abortchar, int abortvalue)
    {
        std::string input = "";
        char inputchar = abortchar;
        float output;
        while (true)
        {
            std::getline(std::cin, input);
            std::stringstream mystream(input);
            if (mystream >> output)
            {
                if((output <= max) && (output >= min)) return output;
                std::cout << "Value out of range (" << min << "-" << max << "), try again :" << std::endl;
            }
            else
            {
                // clear bad read flags, so we can read the same input again
                mystream.clear();  
                if((mystream >> inputchar) && (inputchar == abortchar)) return abortvalue;
                std::cout << "Invalid input, try again :" << std::endl;
            } 
            
        }
    }

    // get a valid non whitespace string
    std::string getStringFromCIN()
    {
        return getStringFromCIN(0);
    }

    // get a valid non whitespace string with length > minlength
    std::string getStringFromCIN(int minlength)
    {
        std::string input = "";

        while(true)
        {
            std::getline(std::cin, input);
            boost::algorithm::trim(input);

            if(input.length() >= (unsigned)minlength ) break;

            std::cout << "Input was not long enough, try again :" << std::endl;

        }

        return input;


    }

}