#include "PrintString.h"

namespace test
{
    void PrintCapacity(const MyString& s)
    {
        std::cout << s.GetCapacity() << std::endl;
    }

    void PrintSize(const MyString s)
    {
        std::cout << s.GetSize() << std::endl;
    }
}