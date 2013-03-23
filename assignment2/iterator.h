#ifndef _BKTITER_
#define _BKTITER_

#include <iostream>
#include "bucket_string.h"

namespace mrxben001
{
    class iterator
    {
    public:
        // SPECIAL MEMBER FUNCTIONS
        // - CONSTRUCTOR
        iterator(bucket_string & subjectbs);
        // - DESTRUCTOR
        ~iterator();
        // - COPY CONSTRUCTOR
        iterator(const iterator& other);
        // - COPY ASSIGMENT OPERATOR
        iterator& operator=(const iterator& other);



        void operator++();
        iterator & operator+=(int i);
        iterator & operator+(int i);

        void operator--();
        iterator & operator-=(int i);
        iterator & operator-(int i);

        bucket * operator *();
    private:
        // the bucketstring this is iterating through
        bucket_string &subject;
        bucket * target;
    };
}

#endif