#include <iostream>
#include <cassert>

#include "MyString.h"
#include "PrintString.h"

int main()
{
    test::MyString s1("So nyun");

    test::PrintCapacity(s1);
    test::PrintSize(s1);

    return 0;
}