#ifndef MAIN_H_
#define MAIN_H_



#include <iostream>
#include <string>
#include <sstream>

#include "input_utils.h"

#include "cmdline_parser.h"
#include "student_record.h"
#include "database.h"

int main(int argc, char * argv[]);

namespace mrxben001
{
    void printmenutext(); 
    void clearStdOut();
    
}

#endif /* MAIN_H_ */