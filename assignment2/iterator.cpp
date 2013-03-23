#include "iterator.h"

namespace mrxben001
{
    iterator::iterator(bucket_string& subjectbs) : subject(subjectbs)
    {
        target = subject.head;
        position = 0;
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
        position = other.position;
    }

    iterator& iterator::operator=(const iterator& other)
    {
        if (this != &other)
        {
            this->subject = bucket_string(other.subject);
            this->target = this->subject.head;
            this->position = other.position;
        }
        return *this;
    }

    bool iterator::operator==(const iterator& other)
    {
        if (this == &other) return true;

        if (this->target != other.target) return false;

        return (this->position == other.position);
    }

    bool iterator::operator!=(const iterator& other)
    {

        if (this->target != other.target) return true;
        if (this == &other) return false;
        return (this->position != other.position);
    }

    void iterator::operator++()
    {
        this->operator+=(1);
    }

    iterator & iterator::operator+=(int i)
    {
        for (int j = 0; j < i; ++j)
        {

            // if past the end of the bucket
            if ((position+1)==target->size)
            {
                position+=1;

                // check whether a next bucket exists
                if (target->next != 0)
                {                    
                    target = target->next;
                    position = 0;
                }
                else
                {
                    break;
                }
            }
            else if ((position+1)==(int)std::strlen(target->content))
            {
                position+=1;
                break;
            }
            else
            {
                position+=1;
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
            if (position <= 0)
            {
                if (target->prev != 0)
                {
                    target = target->prev;
                    position = target->size-1;
                }
                else
                {
                    position = -1;
                    break;
                }

            }
            else
            {
                position-=1;
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

    char iterator::tochar()
    {
        if (position >= (int)std::strlen(target->content))
        {
            return '?';
        }
        return target->content[position];
    }

    void iterator::set_target(bucket * newtarget)
    {
        target = newtarget;
    }

    void iterator::dbg()
    {
        std::cout << "/ iterator " << this << std::endl;

        std::cout << "| using bucket_string " << &subject << std::endl;
        std::cout << "| pointing at bucket " << target << "[" << position << "]" << this->tochar() << std::endl;

        std::cout << "\\" << std::endl;
    }
}


