#include "Dog.h"

int main()
{
    inheritance::Dog d1(2, "moly");
    inheritance::Dog d2 = d1;

    d1.SayName();
    d2.SayName();

    return 0;
}