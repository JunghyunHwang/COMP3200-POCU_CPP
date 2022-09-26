#pragma once

namespace point
{
    class Point
    {
    public:
        Point(int x, int y);
        Point(const Point& other);
        virtual ~Point();
        void SetX(int x);
        void SetY(int y);
        int GetX() const;
        int GetY() const;

    private:
        int mX;
        int mY;
    };
}