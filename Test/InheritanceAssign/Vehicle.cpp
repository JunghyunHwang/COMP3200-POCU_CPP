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

        const unsigned int LENGTH = pName - rhs.mName;

        mName = new char[LENGTH + 1];

        for (size_t i = 0; i < LENGTH; ++i)
        {
            mName[i] = rhs.mName[i];
        }

        mName[LENGTH] = '\0';
    }
}