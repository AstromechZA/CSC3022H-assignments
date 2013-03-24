#include "bucket_string.h"
#include "iterator.h"

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

    bucket_string::bucket_string(const char * content) 
    { 
        construct(7); 
        set_content(content);
    }

    bucket_string::bucket_string(const char * content, int bs) 
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

    // DESTRUCTOR
    bucket_string::~bucket_string()
    {
        std::cout << "< Deleting bucket_string (" << this << ")" << std::endl;
        if (head || tail)
        {
            head->delete_next();
            delete head;
        }

    }

    // set content from a char *
    void bucket_string::set_content(const char * content)
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
            return;
        }

        // pointer to position like content
        const char * c = content;

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
                bucket * n = new bucket(bucket_size);
                current->set_next(n);
                n->set_prev(current);
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

    // add content from a char *
    void bucket_string::add_content(const char * content)
    {
        // first check 0 length
        if ( (*content) == '\0')
        {
            return;
        }

        // pointer to position like content
        const char * c = content;

        if (head ==0)
        {
            // assign first bucket            
            head = new bucket(bucket_size);
            tail = head;
        }

        // get last bucket
        bucket * current = tail;        

        char * buffer = new char[bucket_size];
        std::strcpy(buffer, tail->get_content_unsafe());
        buffer[bucket_size] = '\0';
        int offset = std::strlen(tail->get_content_unsafe());

        while( (*c) != '\0')
        {

            if (offset == bucket_size)
            {
                // copy buffer into bucket
                current->set_content(buffer);
                bucket * n = new bucket(bucket_size);
                current->set_next(n);
                n->set_prev(current);
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
                thisn->set_prev(current);
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

    char & bucket_string::operator[](int index)
    {
        bucket * current = head;

        int c = index / bucket_size;

        for (int i = 0; i < c; ++i)
        {
            current = current->get_next();
        }

        return current->get_content_unsafe()[index % bucket_size];

    }
    
    std::ostream& operator<<(std::ostream & os, const bucket_string & bs)
    {

        bucket * bkt = bs.head;
        while (bkt)
        {
            os << bkt->get_content_unsafe();
            bkt = bkt->get_next();
        }
        return os;
    }

    std::istream& operator>>(std::istream & is, bucket_string & bs)
    {

        // bucket pointers
        bucket * current = 0;

        //setup temp buffer
        char * buffer = new char[bs.bucket_size];
        int offset = 0;
        buffer[bs.bucket_size] = '\0';

        //if tail has content copy it in
        if(bs.tail != 0)
        {
            std::strcpy(buffer, bs.tail->get_content_unsafe());          
            offset = std::strlen(bs.tail->get_content_unsafe());   
            current = bs.tail;     
        }

        char c;
        while(is.get(c))
        {

            if (offset == bs.bucket_size)
            {
                if (current == 0)                       // if current == 0, tail == 0 therefore head == 0
                {
                    // assign first bucket            
                    bs.head = new bucket(bs.bucket_size);
                    bs.tail = bs.head;
                    current = bs.tail;
                }

                // copy buffer into bucket
                current->set_content(buffer);
                bucket * n = new bucket(bs.bucket_size);
                current->set_next(n);
                n->set_prev(current);
                current = current->get_next();
                bs.tail = current;

                offset = 0;
            }

            // assign char to bucket
            buffer[offset] = c;

            // move bucket pointer
            offset++;
        }

        //handler remaining characters

        //fill rest of buffer with nulls
        while(offset < bs.bucket_size)
        {
            buffer[offset] = '\0';
            offset++;
        }

        // nodes might not exist at this point
        if (current == 0)                       // if current == 0, tail == 0 therefore head == 0
        {
            // assign first bucket            
            bs.head = new bucket(bs.bucket_size);
            bs.tail = bs.head;
            current = bs.tail;
        }

        current->set_content(buffer);       

        return is;
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

    std::size_t bucket_string::length() const
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

    //

    //

    //

    //

    iterator * bucket_string::begin()
    {
        iterator * i = new iterator(*this);
        return i;
    }

    iterator * bucket_string::end()
    {
        iterator * i = new iterator(*this);
        i->set_target(tail);
        i->position = (tail->length());
        return i;

    }

}