#ifndef _BUCKET_
#define _BUCKET_

#include <string>
#include <iostream>
#include <stdio.h>
#include <cstring>

namespace mrxben001
{
    class bucket
    {
        public:
            friend class iterator;

            bucket(int size);
            ~bucket();

            //copy constructor
            bucket(const bucket & other);

            // PREV
            void set_prev(bucket * n);
            bucket * get_prev();
            void delete_prev();

            // NEXT
            void set_next(bucket * n);
            bucket * get_next();
            void delete_next();

            //CONTENT
            char * get_content_unsafe();
            void set_content(char * src);


            std::size_t length();
            
        private:
            char * content;
            int size;
            bucket * prev;
            bucket * next;
    };
}



#endif 
