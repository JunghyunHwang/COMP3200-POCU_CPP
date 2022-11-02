#include <cassert>
#include <vector>
#include <map>

#include "Lab7.h"
#include "Test.h"

int main()
{
	lab7::TestOfficial();
	lab7::TestWiki();
	lab7::TestConvertVectorToMap();
	lab7::TestGetKeysAndGetValues();
	lab7::TestReverse();
	lab7::TestOperator();
	lab7::TestOutputFormat();

	std::cout << "No prob" << std::endl;

	return 0;
}