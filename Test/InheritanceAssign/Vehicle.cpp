#include "Vehicle.h"

namespace practice
{
	Vehicle::Vehicle(int year, const char* name)
		: mYear(year)
	{
		const char* pName = name;

		while (*pName++ != '\0')
		{
		}

		--pName;

		mName = new char[pName - name + 1];
		memcpy(mName, name, pName - name + 1);
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mYear(other.mYear)
	{
		const char* pName = other.mName;

		while (*pName++ != '\0')
		{
		}

		--pName;

		mName = new char[pName - other.mName + 1];
		memcpy(mName, other.mName, pName - other.mName + 1);
	}

	Vehicle::~Vehicle()
	{
		delete[] mName;
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mYear = rhs.mYear;

		delete[] mName;

		const char* pName = rhs.mName;

		while (*pName++ != '\0')
		{
		}

		--pName;
		mName = new char[pName - rhs.mName + 1];
		memcpy(mName, rhs.mName, pName - rhs.mName + 1);
	}
}