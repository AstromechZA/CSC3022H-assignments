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

        bucket_string( const bucket_string & other);
        bucket_string& operator=(const bucket_string& other);

        void clear();

        std::size_t length();

        void construct(int bucket_size);
        void set_content(char * content);
        void dbg();


        class iterator
        {
        public:
            iterator(const bucket& sometarget);
            bucket& operator*(const iterator& it);
        private:
            bucket * target;
        };

        iterator * begin();
        
    private:
        int bucket_size;
        bucket * head;
        bucket * tail;

    };
}



#endif 