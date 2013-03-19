#include "bucket_string.h"

namespace mrxben001
{
    // CONSTRUCTORS
    bucket_string::bucket_string() 
    { 
        construct(7); 
    }

    bucket_string::bucket_string(int bs) 
    { 
        construct(bs); 
    }

    bucket_string::bucket_string(char * content) 
    { 
        construct(7); 
        set_content(content);
    }

    bucket_string::bucket_string(char * content, int bs) 
    { 
        construct(bs); 
        set_content(content);
    }

    // actual constructor to set the sizes and stuff
    void bucket_string::construct(int bs)
    {
        bucket_size = bs;
        head = 0;
        tail = 0;
    }

    // set content from a char *
    void bucket_string::set_content(char * content)
    {
        // bail if head and tail have already been assigned
        if( head || tail )
        {
            head->delete_next();
            delete head;

            head = 0;
            tail = 0;
        } 

        // first check 0 length
        if ( (*content) == '\0')
        {
            std::cout << "0-length content" << std::endl;
            return;
        }

        // pointer to position like content
        char * c = content;

        // assign first bucket            
        head = new bucket(bucket_size);
        bucket * current = head;
        tail = current;                         // since we are always dealing with the last one

        char * buffer = new char[bucket_size];
        buffer[bucket_size] = '\0';
        int offset = 0;

        while( (*c) != '\0')
        {

            if (offset == bucket_size)
            {
                // copy buffer into bucket
                current->set_content(buffer);

                current->set_next(new bucket(bucket_size));
                current = current->get_next();
                tail = current;

                offset = 0;
            }

            // assign char to bucket
            buffer[offset] = (*c);

            // move bucket pointer
            offset++;

            // move char pointer
            c++;
        }

        // now we have some random characters left in the buffer
        //check whether we don't need to fill stuff
        while(offset < bucket_size)
        {
            buffer[offset] = '\0';
            offset++;
        }

        // copy buffer into bucket
        current->set_content(buffer);
        tail = current;
    }

    // COPY CONSTRUCTOR
    bucket_string::bucket_string( const bucket_string & other)
    {
        // copy size int
        bucket_size = other.bucket_size;

        //initial
        if(other.head == 0)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            //copy the head node
            head = new bucket(*other.head);

            //current pointers
            bucket * current = head;
            bucket * othercurrent = other.head;
            
            //while other current still has nodes
            while(current)
            {
                // get the othernext node
                bucket * othern = othercurrent->get_next();

                // set the othercurrent
                othercurrent = othern;

                if (othercurrent == 0)
                {
                    break;
                }

                // create a copy as the current next

                bucket * thisn = new bucket(*othern);

                current->set_next(thisn); 
           
                current = current->get_next();


                // update tail
                tail = current;
            }


        }
    }

    // COPY ASSIGNMENT CONSTRUCTOR
    bucket_string& bucket_string::operator=(const bucket_string& other)
    {
        if (this != &other)
        {
            bucket_size = other.bucket_size;
            head = 0;
            tail = 0;



            this->clear();
        }
        return *this;
    }
    

    // DESTRUCTOR
    bucket_string::~bucket_string()
    {
        if (head || tail)
        {
            head->delete_next();
            delete head;
        }

    }
    

    void bucket_string::clear()
    {
        if( head || tail )
        {
            head->delete_next();

            head = 0;
            tail = 0;
        }
    }

    std::size_t bucket_string::length()
    {
        int l = 0;
        bucket * n = head;
        while(n)
        {
            l+=n->length();
            n = n->get_next();
        }
        return l;
    }

    void bucket_string::dbg()
    {
        std::cout << "/ bucket_string(" << this << "):" << std::endl;
        std::cout << "|    bucket size: " << bucket_size << std::endl;
        std::cout << "|    head bucket: " << head << std::endl;

        bucket * bkt = head;
        while (bkt)
        {
            std::cout << "|      bucket: (" << bkt << ") \"" << bkt->get_content_unsafe() << "\"" << std::endl;
            bkt = bkt->get_next();
        }

        std::cout << "|    tail bucket: " << tail << std::endl;
        std::cout << "\\    string length: (" << length() << ")" << std::endl;
    }

    bucket_string::iterator * bucket_string::begin()
    {
        return new iterator(head);
    }

    bucket_string::iterator::iterator(const bucket& sometarget)
    {
        target = sometarget;
    }

}