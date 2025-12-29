#pragma once
#include <cstddef> 
#include <iostream> //delete


template <typename T, std::size_t BUFSIZE>
class CircularBuffer 
{
public: //private
    T buffer[BUFSIZE]{};
    size_t start = 0;
    size_t endind = 0;
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
    CircularBuffer(size_t count, const T& value) //ok
    {
        for (size_t i = 0; i < count; i++)
            push_back(value);
    }
    CircularBuffer(std::initializer_list<T> init) //ok
    {
        for (const auto& value : init)
            push_back(value);
    }




    size_t begin() //ok
    {
        return start;
    }




    size_t end() //ok
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


  











    T at(const size_t& pos) //redo
    {
        return buffer[pos];
    }



    void print() //delete
    {
        for (int i = 0; i < BUFSIZE; i++)
        {
            std::cout << buffer[i] << std::endl;
        }
    }




private:

};