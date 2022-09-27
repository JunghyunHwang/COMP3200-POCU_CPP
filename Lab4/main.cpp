#include <iostream>

#include "Point.h"
#include "PolyLine.h"
#include "Test.h"

int main()
{
    testcase::TestOfficial();
    testcase::TestPointOperator();
    testcase::TestMinBoundingRectangle();
    testcase::TestPolyLineOperator();

    std::cout << "No prob" << std::endl;

    return 0;
}
