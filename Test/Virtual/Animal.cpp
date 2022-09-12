#include <iostream>
#include "Animal.h"

namespace testvirtual
{
    Animal::Animal(int age)
        : mAge(age)
    {
    }

    void Animal::Speak()
    {
        std::cout << "Hi I'm animal" << std::endl;
    }

    int Animal::GetAge() const
    {
        return mAge;
    }
}