#ifndef _BKT_STRING_
#define _BKT_STRING

#include <string>
#include <iostream>
#include <stdio.h>
#include <cstring>

namespace mrxben001
{
    class bucket
    {
        public:
            bucket(int size);
            ~bucket();

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
