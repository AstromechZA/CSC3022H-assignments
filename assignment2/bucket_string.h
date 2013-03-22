#ifndef _BKT_STRING_
#define _BKT_STRING_

#include <string>
#include <iostream>
#include <stdio.h>

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
        bucket_string(char * content);
        bucket_string(char * content, int bucket_size);
        ~bucket_string();  

        bucket_string( const bucket_string & other);
        bucket_string& operator=(const bucket_string& other);

        void clear();

        std::size_t length() const;

        void construct(int bucket_size);
        void set_content(char * content);
        void dbg();

        iterator * begin();
        
    private:
        int bucket_size;
        bucket * head;
        bucket * tail;

    };
}



#endif 