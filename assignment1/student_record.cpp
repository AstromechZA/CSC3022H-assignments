
#include "student_record.h"

namespace mrxben001
{
    student_record::student_record(std::string n, std::string sn, std::string sNum, std::string cR)
    {
        name = n;
        surname = sn;
        studentNumber = sNum;
        classRecord = cR;

        // Extract marks from classrecord string
        classMarks.clear();

        std::stringstream crstream;
        crstream << cR;
        float mark;

        crstream >> mark;
        while(!crstream.fail())
        {
            classMarks.push_back(mark);
            crstream >> mark;
        }

    }

    std::string student_record::encode()
    {
        return name + "|" + surname + "|" + studentNumber + "|" + classRecord;
    }

    std::string student_record::getName()
    {
        return name;
    }

    std::string student_record::getSurname()
    {
        return surname;
    }

    std::string student_record::getStudentNumber()
    {
        return studentNumber;
    }

    std::string student_record::getClassRecordMarks()
    {
        std::stringstream out;

        for (std::vector<float>::iterator it=classMarks.begin(), end = classMarks.end(); it < end; it++)
            out << *it << " ";

        return out.str();
    }

    float student_record::getClassRecordAvg()
    {
        if(classMarks.size() ==0 )return 0;
        float total = 0;
        int count = 0;

        for (std::vector<float>::iterator it=classMarks.begin(), end = classMarks.end(); it < end; it++)
        {
            total+=*it;
            count++;
        }

        return total / count;
    }
}