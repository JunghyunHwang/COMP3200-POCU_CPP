#include "Student.h"

namespace test
{
	unsigned int Student::mCount = 1;

	Student::Student(const char* name)
		: mId(mCount++)
		, mName(name)
	{
	}

	bool Student::operator<(const Student& rhs) const
	{
		if (mName == rhs.mName)
		{
			return mId < rhs.mId;
		}

		return mName < rhs.mName;
	}
}
