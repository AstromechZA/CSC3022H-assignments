#include "database.h"

namespace mrxben001
{
    // CONSTRUCTOR
    database::database(std::string db)
    {
        databasefile = db;
        datahaschanged = false;
        students.clear();
    }

    // DESTRUCTOR
    // this will be needed to clean up the linked list and other pointers.
    database::~database()
    {
        std::cout << "Database cleanup" << std::endl;
    }

    // RETURN a string copy of the database file name
    std::string database::getDatabaseFileName()
    {
        return "" + databasefile;
    }

    // READ the database from the file stored in 'databasefile'
    void database::readDatabaseFromFile()
    {
        std::cout << "-=- READING DATABASE FROM FILE -=-" << std::endl;

        // IF the student list has student objects, clear it. Extra students must be added 
        //    AFTER loading from the file.
        if (students.size() > 0)
        {
            std::cout << "Database is not empty. Clearing before importing." << std::endl;
            students.clear();
            datahaschanged = false;
        }

        std::ifstream dbs(databasefile.c_str());

        // IF the file does not exist, fail
        if (not dbs)
        {
            std::cout << "Unable to read from \"" << databasefile << "\". File does not exist." << std::endl;
        }
        else
        {
            // store line in this
            std::string line;

            std::vector <std::string> parts;

            // read lines one at a time
            while (getline(dbs, line)>0)
            {     
                //split line by delimeter '|'
                boost::split(parts, line, boost::is_any_of("|"));

                if (parts.size() == 4)
                {
                    // sanitise input just in case
                    // TRIM all fields
                    // ONLY the class record can be empty

                    boost::algorithm::trim(parts[0]);
                    boost::algorithm::trim(parts[1]);
                    boost::algorithm::trim(parts[2]);
                    boost::algorithm::trim(parts[3]);

                    // IF lengths are fine, continue
                    if ((parts[0].length() > 0) && (parts[1].length() > 0) && (parts[2].length() > 0))  
                    {
                        // Force the student number to be lower case.
                        std::transform(parts[2].begin(), parts[2].end(), parts[2].begin(), ::tolower);

                        std::cout << "Adding " << parts[2] << std::endl;

                        addstudentInOrder(new student_record( parts[0], parts[1], parts[2], parts[3] ));

                        continue;
                    }   
                }
       
                std::cout << "Could not read line \"" << line << "\". Skipping." << std::endl;
            }
        }

        dbs.close();

    }

    /*
    Display a list of all the students along with their marks
    eg:

    Number     Name            Surname         Grade
    ---------- --------------- --------------- -------
    mrxben001  Ben             Meier           44.00 %
    jhnjoh022  John            Johnson         32.50 %
    mrkbob045  Bob             Markson         52.00 %
    aaaaaa999  Graham          Pretorius       20.50 %
    ---------- --------------- --------------- -------

    */
    void database::displayAllStudents()
    {
        std::cout << "-=- DISPLAY ALL STUDENTS -=-" << std::endl;
        std::cout << "Listing " << students.size() << " students: " << std::endl;
        std::cout << "Number     Name            Surname         Grade" << std::endl;
        std::cout << "---------- --------------- --------------- -------" << std::endl;

        for (std::list<student_record *>::iterator spointer = students.begin(), end = students.end(); spointer != end; ++spointer) 
        {
            std::printf("%-10s %-15s %-15s %-3.2f %%\n", 
                (*spointer)->getStudentNumber().c_str(),                
                (*spointer)->getName().c_str(),
                (*spointer)->getSurname().c_str(),
                (*spointer)->getClassRecordAvg()
            );
        }

        std::cout << "---------- --------------- --------------- -------" << std::endl;

    }

    /*
    Add a new student to the end of the list
    
    */
    void database::addAStudent()
    {
        std::cout << "-=- ADD A STUDENT -=-" << std::endl;

        std::cout << "-=- Enter the student's name: -=-" << std::endl;
        std::string name = getStringFromCIN();

        std::cout << "-=- Enter the student's surname: -=-" << std::endl;
        std::string surname = getStringFromCIN();

        std::cout << "-=- Enter the student's student number: -=-" << std::endl;
        std::string sn = getStringFromCIN(9);

        std::cout << "-=- Enter the student's marks, one line at a time. Enter 'x' to stop : -=-" << std::endl;
        std::stringstream cr;
        float x;
        while(true)
        {
            x = getFloatFromCIN(0,100,'x',-1);
            if(x==-1) break;
            cr << x << " ";
        }

        std::transform(sn.begin(), sn.end(), sn.begin(), ::tolower);

        std::cout << "Adding " << sn << std::endl;

        std::list<student_record *>::iterator ips = students.begin();
        bool found = moveIterToStudent(&ips, sn);
        if(found)
        {
            std::cout << "Conflict with existing record. Replacing." << std::endl;
            students.erase(ips);
        }

        students.push_back( new student_record( name, surname, sn, cr.str() ));
        datahaschanged = true;
    }

    void database::gradeAStudent()
    {
        std::cout << "-=- GRADE A STUDENT -=-" << std::endl;

        std::cout << "-=- Enter the student's student number: -=-" << std::endl;
        std::string sn = getStringFromCIN(9);
        boost::algorithm::trim(sn);
        std::transform(sn.begin(), sn.end(), sn.begin(), ::tolower);

        std::list<student_record *>::iterator ips = students.begin();
        bool found = moveIterToStudent(&ips, sn);
        if (found)
        {
            std::cout << "Found matching student:" << std::endl;
            std::cout << "Number     Name            Surname         Marks" << std::endl;
            std::cout << "---------- --------------- --------------- -----" << std::endl;
            std::printf("%-10s %-15s %-15s %s\n", 
                (*ips)->getStudentNumber().c_str(),                
                (*ips)->getName().c_str(),
                (*ips)->getSurname().c_str(),
                (*ips)->getClassRecordMarks().c_str()                
            );

            std::cout << "---------- --------------- --------------- -----" << std::endl;

            std::printf("Class Record: %3.2f\n", (*ips)->getClassRecordAvg());

        }
        else
        {
            std::cout << "No Student found with student number \"" << sn << "\"." << std::endl;
        }
    }

    void database::displayAStudent()
    {
        std::cout << "-=- DISPLAY A STUDENT -=-" << std::endl;

        std::cout << "-=- Enter the student's student number: -=-" << std::endl;
        std::string sn = getStringFromCIN(9);
        boost::algorithm::trim(sn);
        std::transform(sn.begin(), sn.end(), sn.begin(), ::tolower);

        std::list<student_record *>::iterator ips = students.begin();
        bool found = moveIterToStudent(&ips, sn);
        if (found)
        {
            std::cout << "Found matching student." << std::endl << std::endl;
            std::cout << "Number     Name            Surname         Marks" << std::endl;
            std::cout << "---------- --------------- --------------- -----" << std::endl;
            std::printf("%-10s %-15s %-15s %s\n", 
                (*ips)->getStudentNumber().c_str(),                
                (*ips)->getName().c_str(),
                (*ips)->getSurname().c_str(),
                (*ips)->getClassRecordMarks().c_str()
            );
            std::cout << "---------- --------------- --------------- -----" << std::endl;

        }
        else
        {
            std::cout << "No Student found with student number \"" << sn << "\"." << std::endl;
        }

    }

    void database::deleteAStudent()
    {
        std::cout << "-=- DELETE A STUDENT -=-" << std::endl;

        std::cout << "-=- Enter the student's student number: -=-" << std::endl;
        std::string sn = getStringFromCIN(9);
        boost::algorithm::trim(sn);
        std::transform(sn.begin(), sn.end(), sn.begin(), ::tolower);

        std::list<student_record *>::iterator ips = students.begin();
        bool found = moveIterToStudent(&ips, sn);
        if (found)
        {
            std::cout << "Found matching student:" << std::endl;
            std::cout << "Number     Name            Surname         Marks" << std::endl;
            std::cout << "---------- --------------- --------------- -----" << std::endl;
            std::printf("%-10s %-15s %-15s %s\n", 
                (*ips)->getStudentNumber().c_str(),                
                (*ips)->getName().c_str(),
                (*ips)->getSurname().c_str(),                
                (*ips)->getClassRecordMarks().c_str()
            );
            std::cout << "---------- --------------- --------------- -----" << std::endl;

            std::cout << "Are you sure you want to delete this student?" << std::endl;
            std::cout << " 0 : No" << std::endl;
            std::cout << " 1 : Yes" << std::endl;

            int r = getIntFromCIN(0,1,'q',0);

            if (r==1)
            {
                students.erase(ips);
                std::cout << "Deleted." << std::endl;
                datahaschanged = true;
            }

        }
        else
        {
            std::cout << "No Student found with student number \"" << sn << "\"." << std::endl;
        }


    }

    void database::saveDatabaseToFile()
    {
        std::cout << "-=- SAVE DATABASE -=-" << std::endl;
        if (datahaschanged)
        {
            std::cout << "Database has changed and will be overwritten. Are you sure you want to continue?" << std::endl;
            std::cout << " 0 : No" << std::endl;
            std::cout << " 1 : Yes" << std::endl;

            int r = getIntFromCIN(0,1,'q',0);

            if (r==1)
            {
                std::ofstream outfile;
                outfile.open(databasefile.c_str());

                for (std::list<student_record *>::iterator current = students.begin(), end = students.end(); current != end; ++current) 
                {
                    outfile << (*current)->encode() << std::endl;
                }

                outfile.flush();
                outfile.close();

                datahaschanged = false;
            }

        }
        else
        {
            std::cout << "Database has not changed. Save is not required." << std::endl;
        }


    }

    bool database::moveIterToStudent(std::list<student_record *>::iterator * spointer, std::string number)
    {
        for (std::list<student_record *>::iterator end = students.end(); (*spointer) != end; ++(*spointer)) 
        {
            if ( (*(*spointer))->getStudentNumber().compare(number) == 0) return true;
        }

        return false;
    }

    void database::addstudentInOrder(student_record * student)
    {
        bool inserted = false;
        std::list<student_record *>::iterator current = students.begin();
        std::list<student_record *>::iterator end = students.end();

        std::string sn = student->getStudentNumber();
        std::cout << "Inserting " << sn << std::endl;
        int comp = 0;

        // loop through all items while we havn't inserted the item
        while(current != end)
        {

            comp = (*current)->getStudentNumber().compare(sn);
            
            if (comp < 0){ ++current; continue;}
            // IF EQUAL, remove duplicate
            if (comp==0)
            {
                std::cout << "Conflict with existing record. Replacing." << std::endl;
                current = students.erase(current);
            }

            students.insert( current, student );
            inserted = true;
            break;
        }

        if (!inserted)
        {
            students.push_back( student );
        }

    }


}