#include <iostream>

#include "Animal.h"
#include "Cat.h"

using namespace test;

int main()
{
    Cat* pet1 = new Cat(3, "Joly");
    Animal* pet2 = static_cast<Animal*>(pet1);
    pet2->Speak();

    delete pet1;

    return 0;
}