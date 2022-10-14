#include <cassert>

#include "Point.h"
#include "PolyLine.h"

int main()
{
    test::PolyLine pl;

    test::Point p1;
    test::Point p2;

    assert(p1 == p2);
    assert(pl.GetP1() == p1);
    assert(pl.GetP2() == p2);

    return 0;
}