#include <iostream>

#include "Test.h"

int main()
{
    testcase::testOfficial();
    testcase::testWiki1();
    testcase::TestAssignmentOperator();
    testcase::TestCopyConstructor();
    testcase::TestAddTime();
    testcase::TestGetTimeEntry();
    testcase::TestGetTotalTime();
    testcase::TestGetAverageTime();
    testcase::TestGetStandardDeviation();
    testcase::TestGetName();

	std::cout << "No prob" << std::endl;

    return 0;
}
