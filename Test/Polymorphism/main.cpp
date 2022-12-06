#include <memory>

#include "StudentFee.h"
#include "EngStudent.h"
#include "MbaStudent.h"

using namespace test;

int main()
{
	StudentFee* eng = new EngStudent();
	StudentFee* mba = new MbaStudent();

	eng->PrintFee();
	mba->PrintFee();

	std::unique_ptr<StudentFee> uniqueEng = std::make_unique<EngStudent>();
	std::unique_ptr<StudentFee> uniqueMba = std::make_unique<MbaStudent>();

	uniqueEng->PrintFee();
	uniqueMba->PrintFee();

	return 0;
}