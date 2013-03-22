#ifndef _BKTITER_
#define _BKTITER_

#include <iostream>
#include "bucket_string.h"

namespace mrxben001
{
    class iterator
    {
    public:
        iterator(const bucket_string & subjectbs);

        void operator++();
        iterator & operator+=(int i);

        void operator--();
        iterator & operator-=(int i);

        bucket * operator *();
    private:
        // the bucketstring this is iterating through
        const bucket_string &subject;
        bucket * target;
    };
}

#endif