#pragma once

namespace test
{
	class StudentFee
	{
	public:
		StudentFee() = default;
		virtual ~StudentFee() = default;

		virtual void PrintFee() const = 0;
	};
}

