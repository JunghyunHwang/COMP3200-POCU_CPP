#include "Exponent.h"

namespace middlemath
{
    Exponent::Exponent(int base, float exponent)
        : mBase(base)
        , mExponent(exponent)
    {
    }
    
    Exponent::Exponent(int base)
        : mBase(base)
        , mExponent(1)
    {
    }

    float Exponent::Calculate() const
    {
        return std::pow(mBase, mExponent);
    }

    Exponent Exponent::operator*(const Exponent& rhs)
    {
        Exponent number(mBase, mExponent + rhs.mExponent);
        return number;
    }

    Exponent Exponent::operator/(const Exponent& rhs)
    {
        Exponent number(mBase, mExponent - rhs.mExponent);
        return number;
    }

    Exponent Exponent::operator^(float exponent)
    {
        Exponent number(mBase, mExponent * exponent);
        return number;
    }

    bool Exponent::operator==(const Exponent& rhs)
    {
        return (mBase == rhs.mBase && mExponent == rhs.mExponent);
    }

    std::ostream& operator<<(std::ostream& os, const Exponent& rhs)
    {
        os << "base: " << rhs.mBase << ", ";
        os << "exponent: " << rhs.mExponent << ", ";
        os << "result: " << rhs.Calculate() << std::endl;

        return os;
    }

    Exponent operator*(int lhs, const Exponent& rhs)
    {
        Exponent e(lhs, 1 + rhs.mExponent);
        return e;    
    }

    Exponent operator/(int lhs, const Exponent& rhs)
    {
        Exponent e(lhs, 1 - rhs.mExponent);
        return e;
    }
}