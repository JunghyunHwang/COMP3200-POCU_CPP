#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(MAX_PASSENGERS_COUNT)
		, mTrailer(nullptr)
	{
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, mTrailer(nullptr)
	{
		if (other.mTrailer != nullptr)
		{
			mTrailer = new Trailer(*other.mTrailer);
		}
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		Vehicle::operator=(rhs);

		if (mTrailer != nullptr)
		{
			delete mTrailer;
		}

		if (rhs.mTrailer == nullptr)
		{
			delete mTrailer;
			mTrailer = nullptr;

			return *this;
		}

		mTrailer = new Trailer(*rhs.mTrailer);

		return *this;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != nullptr)
		{
			return false;
		}

		mTrailer = new Trailer(*trailer);
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = nullptr;

		return true;
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int totalWeigth = GetTotalWeight();

		if (mTrailer != nullptr)
		{
			totalWeigth += mTrailer->GetWeight();
		}

		if (totalWeigth <= 80)
		{
			return 480;
		}
		else if (totalWeigth > 350)
		{
			return 300;
		}
		else if (totalWeigth > 260)
		{
			return 380;
		}
		else if (totalWeigth > 160)
		{
			return 400;
		}
		else if (totalWeigth > 80)
		{
			return 458;
		}

		assert(false);
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}