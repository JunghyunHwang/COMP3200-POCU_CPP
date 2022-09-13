#include "Cat.h"

using namespace testvirtual;

int main()
{
    Animal* myCat = new Cat(2, "phang");
    myCat->Speak();

    return 0;
}
