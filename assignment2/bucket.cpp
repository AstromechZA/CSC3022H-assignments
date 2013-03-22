#include "bucket.h"

namespace mrxben001
{

    bucket::bucket(int s)
    {
        size = s;
        content = new char[size];
        next = 0;
        prev = 0;
    }

    bucket::~bucket()
    {
        //empty TODO
    }

    bucket::bucket(const bucket & other)
    {
        size = other.size;
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
        next = 0;   // no next, this is an isolated bucket
        prev = 0;
    }

    char * bucket::get_content_unsafe()
    {
        return content;
    }

    void bucket::set_content(char * src)
    {
        content = new char[size];
        std::strcpy(content, src);
    }

    bucket * bucket::get_prev()
    {
        return prev;
    }

    void bucket::set_prev(bucket * p)
    {
        prev = p;
    }


    bucket * bucket::get_next()
    {
        return next;
    }

    void bucket::set_next(bucket * n)
    {
        next = n;
    }

    void bucket::delete_next()
    {
        if (next) next->delete_next();
        delete next;
    }

    std::size_t bucket::length()
    {
        return std::strlen(content);
    }

}