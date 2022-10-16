#pragma once

namespace test
{
    class Point
    {
    public:
        Point(int x, int y);
        ~Point();

        static void Increase();
    private:
        void doMagic();

    private:
        int mX;
        int mY;
        static unsigned int mCount;
    };
}