#pragma once

#include <vector>

namespace lab6
{
	enum
	{
		MIN = 0x80000000,
		MAX = 0x7fffffff
	};

	int Sum(const std::vector<int>& v);
	int Min(const std::vector<int>& v);
	int Max(const std::vector<int>& v);
	float Average(const std::vector<int>& v);
	int NumberWithMaxOccurrence(const std::vector<int>& v);
	void SortDescending(std::vector<int>& v);
	void QuickSortRecursive(std::vector<int>& v);
}