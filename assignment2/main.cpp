// Main Class

#include "main.h"
#include "iterator.h"

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
        if (vm.count("help"))
        {
            std::cout << desc << std::endl;  
            // TODO return 0;
        }
        else
        {
            // notify for any errors or anything
            boost::program_options::notify(vm);
        }      
    }
    catch (boost::program_options::error& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
        std::cerr << desc << std::endl; 
        return 1;
    }
    // ============================= */
    using namespace mrxben001;

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char redfox[] = "the red fox jumped over the lazy brown dog."; 
    char lorem[] = "Lorem ipsum";

    // ===== TESTS =====
    /*
    // CREATE
    std::cout << "Create new bktstring \"" << alphabet << "\"" <<std::endl;
    bucket_string bstring( alphabet, 10);

    bstring.dbg();
    //------------------------

    
    // SET CONTENT
    std::cout << "Change its content to \"" << redfox << "\"" <<std::endl;
    bstring.set_content(redfox);

    bstring.dbg();
    //------------------------

    // COPY CONSTRUCTOR
    std::cout << "Copy constructor" <<std::endl;
    bucket_string bstring2(bstring);

    bstring2.dbg();
    //------------------------

    // COPY ASSIGNMENT
    std::cout << "Copy assignment" <<std::endl;
    bucket_string bstring3;
    bstring3 = bstring;

    bstring3.dbg();
    //------------------------
    
    // CLEAR CONTENT
    std::cout << "Clear bucket_string" <<std::endl;
    bstring.clear();

    bstring.dbg();
    //------------------------

    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
    
    bstring.set_content(lorem);

    bstring.dbg();
    */

    bucket_string one(alphabet);

    iterator iter = *one.begin();

    std::cout << (*iter)->get_content_unsafe() << std::endl;
    iter+=1;
    ++iter;
    std::cout << (*iter)->get_content_unsafe() << std::endl;
    --iter;
    std::cout << (*iter)->get_content_unsafe() << std::endl;
    iter = iter + 1;
    std::cout << (*iter)->get_content_unsafe() << std::endl;
    iter = iter - 1;
    std::cout << (*iter)->get_content_unsafe() << std::endl;

    one.dbg();

    
    return 0;
}

