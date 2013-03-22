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
            
            bucket * next;
    };
}



#endif 
