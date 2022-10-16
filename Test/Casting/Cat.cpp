#include "Cat.h"

namespace test
{
    Cat::Cat(unsigned int age, const char* name)
        : Animal(age)
        , mName(name)
    {
    }

    Cat::~Cat()
    {
    }

    void Cat::Speak() const
    {
        std::cout << "Counting starts" << std::endl;
    }
}