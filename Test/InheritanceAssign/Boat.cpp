#include "Boat.h"

namespace practice
{
	Boat::Boat(int year, const char* name, const char* made)
		: Vehicle(year, name)
	{
		const char* pMade = made;

		while (*pMade++ != '\0')
		{
		}

		--pMade;

		mMade = new char[pMade - made + 1];
		memcpy(mMade, made, pMade - made + 1);
	}

	Boat::Boat(const Boat& other)
		: Vehicle(other)
	{
		const char* pMade = other.mMade;

		while (*pMade++ != '\0')
		{
		}

		--pMade;

		mMade = new char[pMade - other.mMade + 1];
		memcpy(mMade, other.mMade, pMade - other.mMade + 1);
	}

	Boat::~Boat()
	{
		delete[] mMade;
	}

	Boat& Boat::operator=(const Boat& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		Vehicle::operator=(rhs);

		delete[] mMade;

		const char* pMade = rhs.mMade;

		while (*pMade++ != '\0')
		{
		}

		--pMade;

		mMade = new char[pMade - rhs.mMade + 1];
		memcpy(mMade, rhs.mMade, pMade - rhs.mMade + 1);
	}


}