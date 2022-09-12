#pragma once
#include "Animal.h"

namespace testvirtual
{
    class Cat : public Animal
    {
    public:
        Cat(int age, const char* name);
        void Speak();
    private:
        char* mName;
    };
}