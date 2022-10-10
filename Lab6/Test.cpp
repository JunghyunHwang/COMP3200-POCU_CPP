#include "Test.h"

void lab6::TestOfficial()
{
	std::vector<int> v;
	v.reserve(6);
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	float avg = Average(v);
	assert(avg == 6.83333349f);
}

void lab6::TestMinMax()
{
	std::vector<int> v;
	v.reserve(10);

	assert(Min(v) == INT_MAX);
	assert(Max(v) == INT_MIN);

	v.clear();
	v.push_back(-10);
	v.push_back(0);
	v.push_back(1);
	v.push_back(-12812);
	v.push_back(-12);
	v.push_back(389239);
	v.push_back(5);
	v.push_back(-1);
	v.push_back(100);
	v.push_back(3);
	assert(Min(v) == -12812);
	assert(Max(v) == 389239);

	v.clear();
	v.push_back(-10);
	v.push_back(0);
	v.push_back(INT_MIN);
	v.push_back(-12812);
	v.push_back(-12);
	v.push_back(389239);
	v.push_back(5);
	v.push_back(-1);
	v.push_back(INT_MAX);
	v.push_back(3);
	assert(Min(v) == INT_MIN);
	assert(Max(v) == INT_MAX);
}
