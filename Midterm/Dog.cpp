#include "Dog.h"

Dog::Dog(const char* name)
    : Animal(name)
{
}

Dog::~Dog()
{
}

void Dog::PrintName() const
{
    std::cout << "I'm dog named " << mName;
}