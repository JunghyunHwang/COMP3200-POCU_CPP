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

    std::cout << "No prob" << std::endl;

    return 0;
}
