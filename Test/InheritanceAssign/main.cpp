#include <iostream>
#include "Boat.h"

using namespace practice;

int main()
{
    Boat* b1 = new Boat(1995, "Sha", "Korea");
    Boat* b2 = new Boat(1997, "Ark", "Italy");

    std::cout << "b1" << std::endl;
    std::cout << "Year: " << b1->GetYear() << std::endl;
    std::cout << "Name: " << b1->GetName() << std::endl;

    std::cout << "b2" << std::endl;
    std::cout << "Year: " << b2->GetYear() << std::endl;
    std::cout << "Name: " << b2->GetName() << std::endl;

    // *b2 = *b1;

    std::cout << "b1" << std::endl;
    std::cout << "Year: " << b1->GetYear() << std::endl;
    std::cout << "Name: " << b1->GetName() << std::endl;

    std::cout << "b2" << std::endl;
    std::cout << "Year: " << b2->GetYear() << std::endl;
    std::cout << "Name: " << b2->GetName() << std::endl;

    return 0;
}