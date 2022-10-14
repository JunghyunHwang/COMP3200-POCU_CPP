#include "Lab6.h"

namespace lab6
{
	void quickSortDescendingRecursive(std::vector<int>& v, int left, int right);
	int partition(std::vector<int>& v, int left, int right);
	void swap(std::vector<int>& v, int i, int j);

	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			sum += *it;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int result = INT_MAX;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			if (*it < result)
			{
				result = *it;
			}
		}

		return result;
	}

	int Max(const std::vector<int>& v)
	{
		int result = INT_MIN;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			if (*it > result)
			{
				result = *it;
			}
		}

		return result;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.0;
		}

		return static_cast<float>(Sum(v)) / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		std::vector<int> copyInput = v;

		quickSortDescendingRecursive(copyInput, 0, copyInput.size() - 1);

		int currentNum = copyInput[0];
		unsigned int currentOccurrenceCount = 1;

		int maxOccurrenceNum = copyInput[0];
		unsigned int maxOccurrenceCount = 1;

		for (size_t i = 1; i < copyInput.size(); ++i)
		{
			if (currentNum == copyInput[i])
			{
				++currentOccurrenceCount;

				if (maxOccurrenceCount < currentOccurrenceCount)
				{
					maxOccurrenceCount = currentOccurrenceCount;
					maxOccurrenceNum = copyInput[i];
				}
			}
			else
			{
				currentNum = copyInput[i];
				currentOccurrenceCount = 1;
			}
		}

		return maxOccurrenceNum;
	}

	void SortDescending(std::vector<int>& v)
	{
		quickSortDescendingRecursive(v, 0, v.size() - 1);
	}

	void quickSortDescendingRecursive(std::vector<int>& v, int left, int right)
	{
		if (left >= right)
		{
			return;
		}

		int position = partition(v, left, right);

		quickSortDescendingRecursive(v, left, position - 1);
		quickSortDescendingRecursive(v, position + 1, right);
	}

	int partition(std::vector<int>& v, int left, int right)
	{
		int pivot = v[right];
		int i = left;

		for (int j = left; j < right; ++j)
		{
			if (v[j] >= pivot)
			{
				swap(v, i, j);
				++i;
			}
		}

		swap(v, i, right);

		return i;
	}

	void swap(std::vector<int>& v, int i, int j)
	{
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
}