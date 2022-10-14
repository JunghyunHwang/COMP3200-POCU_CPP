#pragma once

#include <iostream>

namespace test
{
    class Point
    {
    public:
        Point();
        Point(int x, int y);
        Point(const Point& other);
        ~Point();

        inline int GetX() const;
        inline int GetY() const;

        bool operator==(const Point& rhs);
        
    private:
        int mX;
        int mY;
    };

    int Point::GetX() const
    {
        return mX;
    }

    int Point::GetY() const
    {
        return mY;
    }
}