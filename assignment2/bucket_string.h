#ifndef _BKT_STRING_
#define _BKT_STRING

#include <string>
#include <iostream>
#include <stdio.h>

#include "bucket.h"

namespace mrxben001
{
    class bucket_string
    {

    public:
        bucket_string();
        bucket_string(int bucket_size);
        bucket_string(char * content);
        bucket_string(char * content, int bucket_size);
        ~bucket_string();  

        std::size_t length();

        void construct(int bucket_size);
        void set_content(char * content);
        void dbg();
        
    private:
        int bucket_size;
        bucket * head;
        bucket * tail;

    };
}



#endif 