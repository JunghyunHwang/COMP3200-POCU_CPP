#pragma once
#include <string>
#include <iostream>s

#include "Animal.h"

namespace test
{
    class Cat : public Animal
    {
    public:
        Cat(unsigned int age, const char* name);
        Cat(const Cat& other);
        ~Cat();

        Cat& operator=(const Cat& rhs);
        void Speak() const;

    private:
        char* mName;
    };
}