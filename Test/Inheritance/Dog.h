#pragma once

#include <string>
#include <iostream>
#include "Animal.h"

namespace inheritance
{
    class Dog : public Animal
    {
    public:
        Dog(unsigned int age, const char* name);
        Dog(const Dog& other);
        virtual ~Dog();

        void SayName() const;

    private:
        std::string mName;
    };
}