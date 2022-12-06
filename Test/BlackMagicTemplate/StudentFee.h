#pragma once

namespace test
{
	template<class T>
	class StudentFee : T
	{
	public:
		void AnnualFee();
	};

	template<typename T>
	void StudentFee<T>::AnnualFee()
	{
		this->Fee();
	}
}
