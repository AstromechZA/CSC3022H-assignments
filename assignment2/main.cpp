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

    std::ifstream filestream (vm["file"].as<std::string>().c_str());

    std::string line;

    if (filestream.is_open())
    {
        if ( filestream.good() )
        {
            getline (filestream,line);
        }
        filestream.close();
    }

    const char * lorem2 = line.c_str();


    bucket_string * one = new bucket_string(lorem2,20);
    one->dbg();

    iterator * iter = one->begin();
    
    ////////////////////////////////////

    iterator * enditer = one->end();

    while( (*iter) != (*enditer))
    {
        std::cout << iter->tochar();
        ++(*iter);
    }

    std::cout << std::endl;

    ///////////////////////////////////

    iterator * first = one->begin();

    do {
        --(*iter);
        std::cout << iter->tochar();        
    } 
    while((*iter) != (*first));

    std::cout << std::endl;

    ////////////////////////////////////

    std::cout << (*one)[1] << std::endl;
    (*one)[4] = '%';
    one->dbg();

    // std::cout << (*iter)->get_content_unsafe() << std::endl;
    // iter+=1;
    // ++iter;
    // std::cout << (*iter)->get_content_unsafe() << std::endl;
    // --iter;
    // std::cout << (*iter)->get_content_unsafe() << std::endl;
    // iter = iter + 1;
    // std::cout << (*iter)->get_content_unsafe() << std::endl;
    // iter = iter - 1;
    // std::cout << (*iter)->get_content_unsafe() << std::endl;

    // one->dbg();

    // iterator end = *one.end();
    // std::cout << (*end)->get_content_unsafe() << std::endl;
    
    // iterator end2 = *one.end();
    // std::cout << ((*end) == (*end2)) << std::endl;
    // std::cout << ((*iter) == (*end2)) << std::endl;

    // iterator * begin = one.begin();
    // begin->dbg();

    // iterator * endoflist = one.end();
    // endoflist->dbg();

    // std::cout << begin << " " << endoflist << std::endl;


    return 0;
}

