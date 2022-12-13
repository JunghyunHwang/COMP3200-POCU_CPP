#pragma once

#include <string>

namespace test
{
	class Student
	{
	public:
		Student(const char* name);
		~Student() = default;

		Student(const Student& other) = default;
		Student& operator=(const Student& rhs) = default;
		bool operator<(const Student& rhs) const;

		inline unsigned int GetId() const;
		inline std::string GetName() const;

	private:
		static unsigned int mCount;
		unsigned int mId;
		std::string mName;
	};

	unsigned int Student::GetId() const
	{
		return mId;
	}

	std::string Student::GetName() const
	{
		return mName;
	}
}
