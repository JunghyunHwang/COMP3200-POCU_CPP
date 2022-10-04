#pragma once

#include "Vehicle.h"
#include "Trailer.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		~Sedan();
		Sedan& operator=(const Sedan& rhs);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		bool Move();

	private:
		const Trailer* mTrailer;
	};
}