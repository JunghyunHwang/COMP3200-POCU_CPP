#include <cassert>
#include <iostream>

#include "MyStack.h"

using namespace test;

int main()
{
    MyStack<int> ms();
    
    ms.Push(1);
    ms.Push(2);
    ms.Push(3);
    ms.Push(4);
    ms.Push(5);

    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << ms.Pop() << std::endl;
    }

    return 0;
}