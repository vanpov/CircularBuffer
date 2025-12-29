#pragma once
#include <cstddef> 
#include <initializer_list> 

template <typename T, std::size_t BUFSIZE>
class CircularBuffer 
{
public: //private
    T buffer[BUFSIZE]{};
    std::size_t start = 0;
    std::size_t endind = 0;
    bool rewrite = 0;
    //good     
    void push_back(const T& value)
    {
        if (rewrite == 0)
        {
            if (endind < BUFSIZE)
            {
                buffer[endind] = value;
                endind++;
            }
            if (endind == BUFSIZE)
            {
                rewrite = 1;
                endind = 0;
            }
        }
        else
        {
            if (endind < BUFSIZE)
            {
                buffer[endind] = value;
                start = endind + 1;
                if (start == BUFSIZE)
                {
                    start = 0;
                }
                endind++;
            } 
            if (endind == BUFSIZE)
            {
                endind = 0;
            }
        }
    }
    CircularBuffer()// ok
    {

    }
    CircularBuffer(std::size_t count, const T& value) //ok
    {
        for (std::size_t i = 0; i < count; i++)
            push_back(value);
    }
    CircularBuffer(std::initializer_list<T> init) //ok
    {
        for (const auto& value : init)
            push_back(value);
    }
    std::size_t begin() //ok
    {
        return start;
    }
    std::size_t end() //ok
    {
        if (endind == 0)
        {
            return BUFSIZE-1;
        }
        else
        {
            return endind-1;
        }
    }
    std::size_t capacity()
    {
        return BUFSIZE;
    }
    T at(std::size_t pos)
    {
        while (pos >= BUFSIZE)
        {
            pos = pos - BUFSIZE;
        }
        return buffer[pos];
    }
    void insert(std::size_t pos, const T& value)
    {
    while (pos >= BUFSIZE)
        {
        pos = pos - BUFSIZE;
        }
    buffer[pos]=value;
    }



private:
};