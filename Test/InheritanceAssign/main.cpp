#include <cassert>
#include <iostream>
#include "Boat.h"

using namespace practice;

int main()
{
    Boat* b1 = new Boat(1995, "Sha", "Korea");
    Boat* b2 = new Boat(1997, "Ark", "Italy");

    Boat* b3 = new Boat(2019, "George", "Korea");
    Boat* b4 = new Boat(*b3);

    assert(b3 != b4);

    std::cout << "b1" << std::endl;
    std::cout << "Year: " << b1->GetYear() << std::endl;
    std::cout << "Name: " << b1->GetName() << std::endl;

    std::cout << "b2" << std::endl;
    std::cout << "Year: " << b2->GetYear() << std::endl;
    std::cout << "Name: " << b2->GetName() << std::endl;

    std::cout << "b3" << std::endl;
    std::cout << "Year: " << b3->GetYear() << std::endl;
    std::cout << "Name: " << b3->GetName() << std::endl;

    std::cout << "b4" << std::endl;
    std::cout << "Year: " << b4->GetYear() << std::endl;
    std::cout << "Name: " << b4->GetName() << std::endl;

     *b2 = *b1;

     assert(b1 != b2);

    std::cout << "b1" << std::endl;
    std::cout << "Year: " << b1->GetYear() << std::endl;
    std::cout << "Name: " << b1->GetName() << std::endl;

    std::cout << "b2" << std::endl;
    std::cout << "Year: " << b2->GetYear() << std::endl;
    std::cout << "Name: " << b2->GetName() << std::endl;

    return 0;
}