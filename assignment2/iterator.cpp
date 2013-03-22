#include "iterator.h"

namespace mrxben001
{
    iterator::iterator(const bucket_string& subjectbs) : subject(subjectbs)
    {
        target = subject.head;

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

    bucket * iterator::operator *()
    {
        return target;
    }
}


