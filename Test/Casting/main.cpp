#include <cassert>
#include <iostream>
#include <string>

#include "Cat.h"
#include "Dog.h"

using namespace test;

int main()
{
    Cat c1(3, "Phang");
    Cat c2(2000, "Mew");
    Cat c3(c2);
    Cat c4 = c1;
    
    assert(c3.GetAge() == 2000);
    c3.Speak();

    assert(c4.GetAge() == 3);
    c4.Speak();

    Animal a1 = static_cast<Animal>(c1);
    a1.Speak();

    Dog d1 = static_cast<Dog>(a1);

    return 0;
}