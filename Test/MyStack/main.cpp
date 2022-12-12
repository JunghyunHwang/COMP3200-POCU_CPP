#include <cassert>
#include <iostream>

#include "MyStack.h"
#include "Vector.h"

using namespace test;

int main()
{
    MyStack<int> ms;

    ms.Push(1);
    ms.Push(2);
    ms.Push(3);
    ms.Push(4);
    ms.Push(5);

    assert(ms.GetSize() == 5);
    assert(ms.Top() == 5);

    for (int i = 4; i >= 0; --i)
    {
        assert(ms.Pop() == i + 1);
    }

    MyStack<Vector*> msV;

    Vector* v1 = new Vector(1, 1);
    Vector* v2 = new Vector(2, 2);
    Vector* v3 = new Vector(3, 3);
    Vector* v4 = new Vector(4, 4);

    msV.Push(v1);
    msV.Push(v2);
    msV.Push(v3);
    msV.Push(v4);

    assert(msV.GetSize() == 4);

    assert(*(msV.Pop()) == *v4);
    assert(*(msV.Pop()) == *v3);
    assert(*(msV.Pop()) == *v2);
    assert(*(msV.Pop()) == *v1);

    msV.Push(v1);
    msV.Push(v2);
    msV.Push(v3);
    msV.Push(v4);
    assert(msV.GetSize() == 4);

    msV.Clear();
    assert(msV.GetSize() == 0);

    delete v1;
    delete v2;
    delete v3;
    delete v4;

    std::cout << "No prob" << std::endl;

    return 0;
}