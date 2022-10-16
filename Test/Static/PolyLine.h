#include <iostream>
#pragma once

namespace test
{
    class PolyLine
    {
    public:
        ~PolyLine();
        inline int GetX() const;
        inline int GetY() const;
    private:
        int mX;
        int mY;
    };

    int PolyLine::GetX() const
    {
        std::cout << "X address: " << &mX << std::endl;
        return mX;
    }

    int PolyLine::GetY() const
    {
        std::cout << "Y address: " << &mY << std::endl;
        return mY;
    }
}