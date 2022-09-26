#include "Point.h"
#include "Line.h"

using namespace point;
using namespace line;

int main()
{
    Point p1(0, 0);
    Point p2(1, 0);

    Line line1(p1, p2);
    Line line2(line1);

    return 0;
}