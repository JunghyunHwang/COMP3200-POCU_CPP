#include "Animal.h"

namespace test
{
    Animal::Animal(unsigned int age)
        : mAge(age)
    {
    }

    Animal::~Animal()
    {
    }

    void Animal::Speak() const
    {
        std::cout << "I'm animal" << std::endl;
    }
}