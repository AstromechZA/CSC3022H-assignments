// Main Class

#include "main.h"

int main(int argc, char * argv[])
{    

    /* Command line argument parsing. 
    *  Doing this explicitly instead of through the cmdline_parser so that we have more
    *  control of the exact performance and stuff-that-happens.
    // ============================= */
    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,?", "Display this help message.")
        ("file,f", boost::program_options::value<std::string>()->required(), "File containing input string.");

    boost::program_options::variables_map vm;
    vm.clear();

    try
    {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) std::cout << desc << std::endl;
        boost::program_options::notify(vm);
    }
    catch (boost::program_options::error& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
        std::cerr << desc << std::endl; 
        return 1;
    }
    // ============================= */
    using namespace mrxben001;

    char test[] = "abcdefghijklmnopqrstuvwxyz";

    bucket_string bstring = bucket_string( test, 10);

    bstring.dbg();

    char test2[] = "johnson";

    bstring.set_content(test2);

    bstring.dbg();


    





    
    return 0;
}

