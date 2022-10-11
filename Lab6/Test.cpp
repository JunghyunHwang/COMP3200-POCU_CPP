#include "Test.h"

void lab6::TestOfficial()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	int sum = lab6::Sum(v);
	int max = lab6::Max(v);
	int min = lab6::Min(v);
	float average = lab6::Average(v);
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	lab6::SortDescending(v);

	assert(sum == 41);
	assert(max == 12);
	assert(min == 3);
	assert(average == 6.83333349f);
	assert(numWithMaxOccurence == 4);

	for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}
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

void lab6::TestSortDesceding()
{
	std::vector<int> nums;
	nums.reserve(10);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(3);
	int expected1[5] = { 5, 4, 3, 2, 1 };

	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected1[i]);
	}

	nums.clear();
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(3);
	int expected2[6] = { 5, 4, 3, 3, 2, 1 };

	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected2[i]);
	}

	nums.clear();
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(6);
	int expected3[10] = { 9, 8, 7, 7, 6, 5, 4, 3, 2, 1 };

	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected3[i]);
	}

	nums.clear();
	nums.push_back(10);
	nums.push_back(9);
	nums.push_back(8);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	int expected4[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };


	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected4[i]);
	}

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(10);
	int expected5[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected5[i]);
	}

	nums.clear();
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	int expected6[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	SortDescending(nums);

	for (size_t i = 0; i < nums.size(); ++i)
	{
		assert(nums[i] == expected6[i]);
	}
}

void lab6::TestMaxOccurrence()
{
	std::vector<int> v;
	int maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == 0);

	v.reserve(10);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == 1);

	v.clear();
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(-3);
	v.push_back(-3);
	v.push_back(-3);
	v.push_back(-7);
	v.push_back(-8);
	v.push_back(-9);
	maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == -3);

	v.clear();
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(-2);
	v.push_back(4);
	v.push_back(4);
	maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == -2 || maxOccurrence == 4);

	v.clear();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == 10);

	v.clear();
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	v.push_back(41234);
	maxOccurrence = NumberWithMaxOccurrence(v);
	assert(maxOccurrence == 41234);
}


