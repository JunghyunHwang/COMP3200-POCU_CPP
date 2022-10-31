#include "Vector.h"

namespace practice
{
    Vector::Vector()
        : mX(0)
        , mY(0)
    {
    }

    Vector::Vector(int x, int y)
        : mX(x)
        , mY(y)
    {
    }

    std::ostream& operator<<(std::ostream& os, const Vector& rhs)
    {
        os << rhs.mX << ", " << rhs.mY;
        return os;
    }
}