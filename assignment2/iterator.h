#ifndef _BKTITER_
#define _BKTITER_

#include <iostream>
#include "bucket_string.h"

namespace mrxben001
{
    class iterator
    {
    public:
        friend class bucket_string;

        // SPECIAL MEMBER FUNCTIONS
        // - CONSTRUCTOR
        iterator(bucket_string & subjectbs);
        // - DESTRUCTOR
        ~iterator();
        // - COPY CONSTRUCTOR
        iterator(const iterator& other);
        // - COPY ASSIGMENT OPERATOR
        iterator& operator=(const iterator& other);

        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
        bool operator>(const iterator& other) const;
        bool operator<(const iterator& other) const;

        void operator++();
        iterator & operator+=(int i);
        iterator & operator+(int i);

        void operator--();
        iterator & operator-=(int i);
        iterator & operator-(int i);

        bucket * operator *();
        char tochar() const;

        void set_target(bucket * newtarget);

        void dbg() const;
    private:
        int offset;
        int index;
        bucket_string * subject;
        bucket * target;
    };
}

#endif