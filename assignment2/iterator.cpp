#include "iterator.h"

namespace mrxben001
{
    iterator::iterator(bucket_string& subjectbs) : subject(subjectbs)
    {
        target = subject.head;
        index = 0;
    }  

    iterator::~iterator()
    {
        // blank the pointers
        // DONT destroy them!
        target = 0;
        subject = 0;
    }

    iterator::iterator(const iterator& other) : subject(other.subject)
    {
        target = subject.head;
        index = other.index;
    }

    iterator& iterator::operator=(const iterator& other)
    {
        if (this != &other)
        {
            this->subject = bucket_string(other.subject);
            this->target = this->subject.head;
            this->index = other.index;
        }
        return *this;
    }

    bool iterator::operator==(const iterator& other) const
    {
        if (this == &other) return true;

        return ((this->target == other.target) && (this->index == other.index));
    }

    bool iterator::operator!=(const iterator& other) const
    {
        //same object
        if (this == &other) return false;

        //index
        return ((&this->subject == &other.subject) && (this->index != other.index));
    }

    bool iterator::operator<(const iterator& other) const
    {
        if (&this->subject != &other.subject) return false;
        return (this->index < other.index);
    }

    bool iterator::operator>(const iterator& other) const
    {
        if (&this->subject != &other.subject) return false;
        return (this->index > other.index);
    }

    void iterator::operator++()
    {
        this->operator+=(1);
    }

    iterator & iterator::operator+=(int i)
    {
        for (int j = 0; j < i; ++j)
        {
            int mpos = index % target->size;    //offset in buffer

            index+=1;

            // am i at the end of a bucket?
            if( (mpos+1) == (int)std::strlen(target->content) )
            {   
                if(target->next == 0)
                {
                    break;
                }
                else
                {
                    target = target->next;
                }
            }
        }
        return *this;
    }

    iterator & iterator::operator+(int i)
    {
        iterator * r = this;
        (*r) += i;
        return *r;
    }

    void iterator::operator--()
    {
        this->operator-=(1);
    }

    iterator & iterator::operator-=(int i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (index > 0)
            {
                index-=1;

                if ( (index % target->size) == (target->size-1) )
                {
                    target = target->prev;
                }

            }

        }
        return *this;
    }

    iterator & iterator::operator-(int i)
    {
        iterator * r = this;
        (*r) -= i;
        return *r;
    }

    bucket * iterator::operator*()
    {
        return target;
    }

    char iterator::tochar() const
    {
        int mod = index % target->size;
        if (mod >= (int)std::strlen(target->content))
        {
            return '?';
        }
        return target->content[mod];
    }

    void iterator::set_target(bucket * newtarget)
    {
        target = newtarget;
    }

    void iterator::dbg() const
    {
        std::cout << "/ iterator " << this << std::endl;

        std::cout << "| using bucket_string " << &subject << std::endl;
        std::cout << "| pointing at bucket " << target << std::endl;
        std::cout << "| " << &subject << "[" << index << "]" << this->tochar() << std::endl;
        std::cout << "\\" << std::endl;
    }
}


