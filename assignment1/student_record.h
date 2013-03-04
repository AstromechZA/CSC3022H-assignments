#ifndef STUDENTRECORD_H_
#define STUDENTRECORD_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace mrxben001
{
    class student_record
    {
        public:
            student_record(std::string n, std::string sn, std::string sNum, std::string cR);       //constructor
            std::string encode();
            std::string getStudentNumber();
            std::string getName();
            std::string getSurname();
            std::string getClassRecordMarks();
            float getClassRecordAvg();
        private:
            std::string name;
            std::string surname;
            std::string studentNumber;
            std::string classRecord;
            std::vector<float> classMarks;

    };
}


#endif 