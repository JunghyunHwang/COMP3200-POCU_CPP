#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <random>

int main()
{
	const size_t SIZE = 10000;
	std::vector<int> v;
	std::vector<int> capacityLog;
	unsigned int capacity = v.capacity();

	std::random_device rd;
	std::mt19937 gen(rd());

	capacityLog.reserve(SIZE);
	capacityLog.push_back(capacity);

	for (size_t i = 0; i < SIZE; ++i)
	{
		v.push_back(gen());

		if (v.capacity() != capacity)
		{
			capacity = v.capacity();
			capacityLog.push_back(capacity);
		}
	}

	std::ofstream fout;
#ifdef _DEBUG
	fout.open("Debug_STL vector realloc test.txt");
#else
	fout.open("Release_STL vector realloc test.txt");
#endif

	fout << std::right;
	unsigned int titleSize = 11;
	fout << std::setw(titleSize * 4 + 1) << std::setfill('-') << " " << std::endl;
	fout << std::setfill(' ');
	fout << std::setw(titleSize) << "Count|";
	fout << std::setw(titleSize) << "Before|";
	fout << std::setw(titleSize) << "After|";
	fout << std::setw(titleSize) << "Size|" << std::endl;
	fout << std::setw(titleSize * 4 + 1) << std::setfill('-') << " " << std::endl;

	for (size_t i = 1; i < capacityLog.size(); ++i)
	{
		unsigned int diff = capacityLog[i] - capacityLog[i - 1];
		fout << std::setfill(' ');
		fout << std::setw(titleSize - 1) << i << "|";
		fout << std::setw(titleSize - 1) << capacityLog[i - 1] << "|";
		fout << std::setw(titleSize - 1) << capacityLog[i] << "|";
		fout << std::setw(titleSize - 1) << diff << "|" << std::endl;
		fout << std::setw(titleSize * 4 + 1) << std::setfill('-') << " " << std::endl;
	}

	std::cout << "No prob" << std::endl;

	return 0;
}