#pragma once
#include <iostream>
#include <utility>

class Dummy
{
public:
    int *num;
    Dummy()
    {
        num = new int{0};
    }
    ~Dummy() { delete num; }

    int get() const { return *num; }

    Dummy(const Dummy &other)
    {
        this->num = new int{};
        *num = other.get();
    }

    Dummy &operator=(const Dummy &other)
    {
        delete num;
        num = new int{};
        *num = other.get();
        return *this;
    }
};

void dummyTest();