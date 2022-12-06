#pragma once
#include <iostream>

#include "StudentFee.h"

namespace test
{
	class EngStudent : public StudentFee
	{
	public:
		EngStudent() = default;
		~EngStudent() = default;

		virtual void PrintFee() const override;
	};
}
