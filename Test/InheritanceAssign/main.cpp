#include <cassert>
#include <string>
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

    assert(b1->GetYear() == 1995);
    assert(strcmp(b1->GetName(), "Sha") == 0);
    assert(strcmp(b1->GetMade(), "Korea") == 0);

    assert(b2->GetYear() == 1997);
    assert(strcmp(b2->GetName(), "Ark") == 0);
    assert(strcmp(b2->GetMade(), "Italy") == 0);

    assert(b3->GetYear() == 2019);
    assert(strcmp(b3->GetName(), "George") == 0);
    assert(strcmp(b3->GetMade(), "Korea") == 0);

    assert(b4->GetYear() == 2019);
    assert(strcmp(b4->GetName(), "George") == 0);
    assert(strcmp(b4->GetMade(), "Korea") == 0);

     *b2 = *b1;

     assert(b1 != b2);

     assert(b2->GetYear() == 1995);
     assert(strcmp(b2->GetName(), "Sha") == 0);
     assert(strcmp(b2->GetMade(), "Korea") == 0);

     std::cout << "No prob" << std::endl;

    return 0;
}