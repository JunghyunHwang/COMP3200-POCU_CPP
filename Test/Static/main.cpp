#include <iostream>
#include "PolyLine.h"

int main()
{
    test::PolyLine pl;

    std::cout << "X: " << pl.GetX() << std::endl;
    std::cout << "Y: " << pl.GetY() << std::endl;

    return 0;
}