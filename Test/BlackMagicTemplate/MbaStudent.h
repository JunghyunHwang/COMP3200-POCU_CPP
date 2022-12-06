#pragma once
#include <iostream>

namespace test
{
	class MbaStudent
	{
	public:
		inline void Fee();
	};

	void MbaStudent::Fee()
	{
		std::cout << "Mba student fee: 100000" << std::endl;
	}
}