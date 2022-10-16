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
        virtual ~Cat();

        void Speak() const;
    private:
        std::string mName;
    };
}