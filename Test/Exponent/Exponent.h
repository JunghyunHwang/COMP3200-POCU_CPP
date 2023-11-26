#pragma once
#include <iostream>

using namespace std;

namespace middlemath
{
    class Exponent
    {
        friend std::ostream& operator<<(std::ostream& os, const Exponent& rhs);
        friend Exponent operator*(int lhs, const Exponent& rhs);
        friend Exponent operator/(int lhs, const Exponent& rhs);
        
    public:
        Exponent(int base, float exponent);
        Exponent(int base);
        Exponent(const Exponent& other) = default;
        ~Exponent() = default;
        
        float Calculate() const;

        Exponent& operator=(const Exponent& rhs) = default;

        Exponent operator*(const Exponent& rhs);
        Exponent operator/(const Exponent& rhs);
        Exponent operator^(float exponent);
        bool operator==(const Exponent& rhs);

    private:
        int mBase;
        float mExponent;
    };
}