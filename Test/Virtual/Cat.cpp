#include <cstring>
#include <iostream>
#include "Cat.h"

namespace testvirtual
{
    Cat::Cat(int age, const char* name)
        : Animal(age)
    {
        size_t nameSize = strlen(name) + 1;

        mName = new char[nameSize];
        strcpy(mName, name);
    }

    Cat::Speak()
    {
        std::cout << "Hi I'm " << mName << std::endl;
    }
}