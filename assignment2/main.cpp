// Main Class

#include "main.h"
#include "iterator.h"
#include "bucket_string.h"

using namespace mrxben001;

// === SOME SHORT TEST STRINGS ========================== */
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char redfox[] = "the red fox jumped over the lazy brown dog."; 
char lorem[] = "Lorem ipsum";

void test_bucket_string_construct_destruct()
{
    std::cout << "TEST: CONSTRUCT/DESTRUCT " << std::endl;

     // Constructor
    std::cout << "CONSTRUCT bs1" << std::endl;
    bucket_string * bs1 = new bucket_string(redfox);                         
    bs1->dbg();                                                             //debug

    // Destructor
    std::cout << std::endl << "DESTRUCT bs1" << std::endl;
    delete bs1;                                                             //free this memory

    // Create another (shorter) bucket string, prove that it uses the memory freed
    // by the destructor previously
    std::cout << std::endl << "CONSTRUCT bs2 in the freed memory" << std::endl;
    bucket_string * bs2 = new bucket_string(alphabet, 10);
    bs2->dbg();

    std::cout << "TEST: Passed " << std::endl;
    delete bs2;
}

void test_bucket_string_copy_construct()
{
    std::cout << "TEST: COPY CONSTRUCT " << std::endl;

    std::cout << "CONSTRUCT bs1" << std::endl;
    bucket_string bs1(redfox);                         
    bs1.dbg(); 

    std::cout << std::endl;

    std::cout << "CONSTRUCT bs2 ( bucket_string bs2(bs1); )" << std::endl;
    bucket_string bs2(bs1);                         
    bs2.dbg(); 

    std::cout << "TEST: Passed " << std::endl;
}

void test_bucket_string_copy_assign()
{
    std::cout << "TEST: ASSIGNMENT " << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);          

    std::cout << "CONSTRUCT bs2 with redfox" << std::endl;
    bucket_string bs2(redfox);

    std::cout << "ASSIGN bs2 to bs1 ( bs1 = bs2; )" << std::endl;
    bs1 = bs2;            

    bs1.dbg(); 

    std::cout << "TEST: Passed " << std::endl;
}

void test_bucket_string_ostream_insertion()
{
    std::cout << "TEST: OSTREAM INSERTION " << std::endl;

    std::cout << "CONSTRUCT bs1" << std::endl;
    bucket_string bs1(redfox);
    bs1.dbg(); 

    std::cout << "Ouput to std::cout ( std::cout << bs1 << std::endl; )" << std::endl;

    std::cout << bs1 << std::endl;

    std::cout << "TEST: Passed " << std::endl;
}

void test_bucket_string_ostream_extraction(const char * filename)
{
    std::cout << "TEST: ISTREAM EXTRACTION " << std::endl;

    std::cout << "CONSTRUCT blank bs1" << std::endl;
    bucket_string bs1(20);
    bs1.dbg();

    std::string temp;
    std::ifstream file (filename);

    if (file.is_open())
    {
        std::cout << "Reading from stream into bs1 ( file >> bs1; ) " << std::endl;
        file >> bs1;
        file.close();
    }
    else
    {
        std::cout << "FILE (" << filename << ")DOES NOT EXIST!" << std::endl;
        std::cout << "TEST 5: Failed " << std::endl;
        return;
    }

    bs1.dbg();

    std::cout << "TEST: Passed " << std::endl;
}

void test_bucket_string_forward_iteration()
{
    std::cout << "TEST: FORWARD ITERATION " << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);                         
    bs1.dbg(); 

    iterator * current = bs1.begin();
    iterator * end = bs1.end();

    while ((*current) != (*end))
    {
        std::cout << (*current).tochar() << std::endl;
        ++(*current);
    }

    std::cout << "TEST: Passed" << std::endl;
    delete current;
    delete end;
}

void test_bucket_string_backward_iteration()
{
    std::cout << "TEST: BACKWARD ITERATION " << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);                         
    bs1.dbg(); 

    iterator * current = bs1.end();
    iterator * begin = bs1.begin();

    do
    {
        --(*current);
        std::cout << (*current).tochar() << std::endl;
    } while ((*current) != (*begin));

    std::cout << "TEST: Passed" << std::endl;
    delete current;
    delete begin;
}

void test_bucket_string_substr()
{
    std::cout << "TEST: SUBSTRING " << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);                         
    bs1.dbg(); 

    iterator * start = bs1.begin();
    iterator * end1 = bs1.begin();
    (*end1)+=10;

    std::cout << "SUBSTRING begin : 10" << std::endl;
    bucket_string& bs2 = bs1.substring(*start, *end1);
    bs2.dbg();

    iterator * end2 = bs1.end();

    std::cout << "SUBSTRING 10 : end" << std::endl;
    bucket_string& bs3 = bs1.substring(*end1, *end2);
    bs3.dbg();


    iterator& i1 = *bs1.begin();
    i1+=1;
    iterator& i2 = i1+1;

    std::cout << "SUBSTRING 1 : 2" << std::endl;
    bucket_string& bs4 = bs1.substring(i1,i2);
    bs4.dbg();

    delete &i1;
    delete &i2;




    std::cout << "TEST: Passed " << std::endl;

    delete start;
    delete end1;
    delete end2;
    delete &bs2;
    delete &bs3;
}

void test_bucket_string_char_append()
{
    std::cout << "TEST: CHAR * APPEND " << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1;                         
    bs1.dbg(); 

    bs1+=redfox;

    bs1.dbg(); 

    bucket_string& bs2 = bs1 + alphabet;
    bucket_string& bs3 = bs2 + bs1;

    bs3.dbg();

    std::cout << "TEST: Passed " << std::endl;

    delete &bs2;
    delete &bs3;
}

void test_bucket_string_insert()
{
    std::cout << "TEST: INSERT" << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);    
    bs1.dbg();

    std::cout << "CONSTRUCT bs2 with lorem ipsum" << std::endl;
    bucket_string bs2(lorem);  

    std::cout << "INSERT bs2 into bs1 at begin+10" << std::endl;
    bucket_string& bs3 = bs1.insert((*bs1.begin())+10, bs2);

    bs3.dbg();

    std::cout << "TEST: Passed " << std::endl;

    delete &bs3;
}

void test_bucket_string_replace()
{
    std::cout << "TEST: REPLACE" << std::endl;

    std::cout << "CONSTRUCT bs1 with alphabet" << std::endl;
    bucket_string bs1(alphabet);    
    bs1.dbg();

    bucket_string bs2(redfox);

    iterator from = (*bs1.begin()) + 3;
    iterator to = (*bs1.begin()) + 20;

    bucket_string& bs3 = bs1.replace(from, to, bs2);

    bs3.dbg();

    std::cout << "TEST: Passed " << std::endl;

    delete &bs3;
}


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
            return 0;
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

    const char * inputfile = vm["file"].as<std::string>().c_str();


    test_bucket_string_construct_destruct();
    std::cout << std::endl;

    test_bucket_string_copy_construct();
    std::cout << std::endl;

    test_bucket_string_copy_assign();
    std::cout << std::endl;



    test_bucket_string_ostream_insertion();
    std::cout << std::endl;

    test_bucket_string_ostream_extraction(inputfile);
    std::cout << std::endl;


    /* NOT NEEDED TESTS
    test_bucket_string_forward_iteration();
    std::cout << std::endl;

    test_bucket_string_backward_iteration();
    std::cout << std::endl;

    test_bucket_string_char_append();
    std::cout << std::endl;

    */


    test_bucket_string_substr();
    std::cout << std::endl;

    test_bucket_string_insert();
    std::cout << std::endl;

    test_bucket_string_replace();
    std::cout << std::endl;
    
    return 0;
}

