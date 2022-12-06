#include "StudentFee.h"
#include "EngStudent.h"
#include "MbaStudent.h"

using namespace test;

int main()
{
	StudentFee<EngStudent> eng;
	StudentFee<MbaStudent> mba;

	eng.AnnualFee();
	mba.AnnualFee();

	return 0;
}