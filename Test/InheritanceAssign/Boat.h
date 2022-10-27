#pragma once

#include <string>
#include "Vehicle.h"

namespace practice
{
    class Boat : public Vehicle
    {
    public:
        Boat(int year, const char* name, const char* made);
        Boat(const Boat& other);
        virtual ~Boat();
        Boat& operator=(const Boat& rhs);

        inline const char* GetMade() const;

    private:
        char* mMade;
    };

    const char* Boat::GetMade() const
    {
        return mMade;
    }
}