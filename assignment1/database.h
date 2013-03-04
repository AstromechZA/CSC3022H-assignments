#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include "student_record.h"
#include "input_utils.h"

namespace mrxben001
{
    class database
    {
        public:
            database(std::string db);       //constructor
            ~database();                    //destructor
            

            // variables
            std::string getDatabaseFileName();
            std::list<student_record *> students;

            // methods

            void readDatabaseFromFile();            
            void saveDatabaseToFile();
            void displayAllStudents();
            void addAStudent();
            void gradeAStudent();
            void displayAStudent();
            void deleteAStudent();

            bool moveIterToStudent(std::list<student_record *>::iterator * spointer, std::string number);

        private:
            std::string databasefile;
            bool datahaschanged;
    };
}


#endif 