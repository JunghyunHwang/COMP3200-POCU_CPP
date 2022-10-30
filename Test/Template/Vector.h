#pragma once
#include <iostream>

namespace practice
{
    class Vector
    {
        friend std::ostream& operator<<(std::ostream& os, const Vector& rhs);
    public:
        Vector();
        Vector(int mX, int mY);
        inline int GetX() const;
        inline int GetY() const;
        
    private:
        int mX;
        int mY;
    };

    int Vector::GetX() const
    {
        return mX;
    }

    int Vector::GetY() const
    {
        return mY;
    }
}