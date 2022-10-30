#include <iostream>
#include <cassert>

#include "MyIntArray.h"
#include "Vector.h"

using namespace practice;

int main()
{
    MyIntArray<int> arrByInt;
    assert(arrByInt.Add(1) == true);
    assert(arrByInt.Add(3) == true);
    assert(arrByInt.Add(-7) == true);
    assert(arrByInt.Add(7) == false);

    for (size_t i = 0; i < arrByInt.GetSize(); ++i)
    {
        std::cout << arrByInt[i] << std::endl;
    }

    MyIntArray<Vector> arrByVector;
    assert(arrByVector.Add(Vector(2, 3)) == true);
    assert(arrByVector.Add(Vector(0, 7)) == true);
    assert(arrByVector.Add(Vector(-2, 4)) == true);
    assert(arrByVector.Add(Vector(-2, 4)) == false);

    for (size_t i = 0; i < arrByVector.GetSize(); ++i)
    {
        std::cout << arrByVector[i] << std::endl;
    }

    std::cout << "No prob" << std::endl;

    return 0;
}