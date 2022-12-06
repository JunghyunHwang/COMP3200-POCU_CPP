#pragma once
#include <iostream>

namespace test
{
	class EngStudent
	{
	public:
		inline void Fee();
	};

	void EngStudent::Fee()
	{
		std::cout << "Eng student fee: 90000" << std::endl;;
	}
}