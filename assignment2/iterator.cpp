#include "iterator.h"

namespace mrxben001
{
    iterator::iterator(bucket_string& subjectbs) : subject(subjectbs)
    {
        target = subject.head;
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
    }

    iterator& iterator::operator=(const iterator& other)
    {
        if (this != &other)
        {
            this->subject = bucket_string(other.subject);
            this->target = this->subject.head;
        }
        return *this;
    }

    void iterator::operator++()
    {
        this->operator+=(1);
    }

    iterator & iterator::operator+=(int i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (target != 0)
            {                    
                target = target->next;
            }
            else
            {
                // something should be thrown or whatever
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
            if (target != 0)
            {                    
                target = target->prev;
            }
            else
            {
                // something should be thrown or whatever
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

    bucket * iterator::operator *()
    {
        return target;
    }
}


