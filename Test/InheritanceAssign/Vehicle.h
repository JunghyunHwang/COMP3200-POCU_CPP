#pragma once

#include <string>

namespace practice
{
    class Vehicle
    {
    public:
        Vehicle(int year, const char* name);
        Vehicle(const Vehicle& other);
        virtual ~Vehicle();

        Vehicle& operator=(const Vehicle& rhs);
        inline int GetYear() const;
        inline const char* GetName() const;

    private:
        int mYear;
        char* mName;
    };

    int Vehicle::GetYear() const
    {
        return mYear;
    }

    const char* Vehicle::GetName() const
    {
        return mName;
    }
}