#include <iostream>

#include "Point.h"
#include "PolyLine.h"
#include "Test.h"

int main()
{
    testcase::TestOfficial();
    testcase::TestPointOperator();
    testcase::TestPolyLineOperator();
    testcase::TestMinBoundingRectangle();
    testcase::TestCaseMain();

    lab4::Point* p1 = new lab4::Point(0, 0);
    lab4::Point* p2 = new lab4::Point(2, 1);

    lab4::PolyLine* pl = new lab4::PolyLine;
    pl->AddPoint(p1);
    pl->AddPoint(p2);

    *p1 = *p2;

    std::cout << (*(*pl)[0]) << std::endl;

    std::cout << "No prob" << std::endl;

    return 0;
}
