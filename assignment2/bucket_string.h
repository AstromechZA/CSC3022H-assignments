#ifndef _BKT_STRING_
#define _BKT_STRING_

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdexcept>


// THIS IS FINE, has no sub includes
#include "bucket.h"

namespace mrxben001
{
    class iterator;
}

// THIS IS THE ISSUE

namespace mrxben001
{

    class bucket_string
    {

    public:
        friend class iterator;

        bucket_string();
        bucket_string(int bucket_size);
        bucket_string(const char * content);
        bucket_string(const char * content, int bucket_size);
        ~bucket_string();  

        bucket_string( const bucket_string & other);
        bucket_string& operator=(const bucket_string& other);

        bucket_string& operator+=(const char * morecontent);        
        bucket_string& operator+(const char * morecontent);
        bucket_string& operator+=(bucket_string& other);        
        bucket_string& operator+(bucket_string& other);

        char & operator[](int index);

        friend std::ostream& operator<<(std::ostream & os, const bucket_string & bs);
        friend std::istream& operator>>(std::istream & is, bucket_string & bs);

        void clear();

        std::size_t length() const;

        void construct(int bucket_size);
        void set_content(const char * content);


        bucket_string& substring(const iterator& start, const iterator& end);
        bucket_string& insert(const iterator& position, bucket_string& bs);
        bucket_string& replace(const iterator& from, const iterator& to, bucket_string& bs);

        void dbg();

        iterator * begin();
        iterator * end();
        
    private:
        int bucket_size;
        bucket * head;
        bucket * tail;

    };
}



#endif 