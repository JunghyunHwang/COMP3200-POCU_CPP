#pragma once

#include <iostream>

class Foo
{
public:
    Foo();
    virtual ~Foo();
    virtual void Print() const;
protected:
    int mX;
};
