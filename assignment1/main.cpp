// Main Class

#include "main.h"

int main(int argc, char * argv[])
{ 
    using namespace mrxben001;
    
    // CMD line parser for the database filename
    cmdline_parser parser;

    // Handle extraordinary exceptions or a bad result. Print USAGE if it is bad.
    try
    {
        if (!parser.process_cmdline(argc, argv)) throw 1;        
    } catch (...) {
        std::cerr << "ERROR : Couldn't process command line arguments." << std::endl << "USAGE: " << std::endl;
        parser.print_help(std::cout); 
        return 1;
    }

    // IF --help was used, print help and return.
    if (parser.should_print_help())
    {
       parser.print_help(std::cout); 
       return 0; 
    } 
    // OTHERWISE start normal running of the program.    


    //First clear the screen
    clearStdOut();

    // Create a database object and assign its database text file
    database * db = new database(parser.get_database_filename());

    std::cout << "-=- STUDENT DATABASE -=-" << std::endl;
    std::cout << " Using database: \"" << db->getDatabaseFileName() << "\"" << std::endl;
    std::cout << std::endl;

    int option = 0;
    while (true)
    {
        printmenutext();
        option = getIntFromCIN(0, 6);
        if (option < 0) break;

        clearStdOut();    

        switch ( option )
        {
            case 0:
                db->readDatabaseFromFile();
                break;
            case 1:
                db->displayAllStudents();
                break;
            case 2:
                db->addAStudent();
                break;
            case 3:
                db->gradeAStudent();
                break;
            case 4:
                db->displayAStudent();
                break;
            case 5:
                db->deleteAStudent();
                break;
            case 6:
                db->saveDatabaseToFile();
                break;
        }

        std::cout << std::endl;
    }

    delete db;

    return 0;
}

namespace mrxben001
{

    /*
    void printmenutext()
    Print the menu options with nice formatting.
    */
    void printmenutext()
    {
        std::cout << "-=- MENU -=- " << std::endl;
        std::cout << " 0 : Read database from file" << std::endl;
        std::cout << " 1 : Display all students" << std::endl;
        std::cout << std::endl;
        std::cout << " 2 : Add a student" << std::endl;
        std::cout << " 3 : Grade a student" << std::endl;
        std::cout << " 4 : Display a student" << std::endl;
        std::cout << " 5 : Delete a student" << std::endl;
        std::cout << std::endl;
        std::cout << " 6 : Save database to file" << std::endl;
        std::cout << "-=- Enter a number (or q to quit) and press enter: -=- " << std::endl;
    }    

    /*
    void clearStdOut()
    Clear std out by resetting the cursor to the top left position and clearing the screen.
    */
    void clearStdOut()
    {
        std::cout << "\033[2J\033[1;1H";  

    }

    

}