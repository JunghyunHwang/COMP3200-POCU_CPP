#pragma once

#include <iostream>

#include "StudentFee.h"

namespace test
{
	class MbaStudent : public StudentFee
	{
	public:
		MbaStudent() = default;
		~MbaStudent() = default;

		virtual void PrintFee() const override;
	};
}
