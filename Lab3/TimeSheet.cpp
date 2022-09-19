#include <cmath>
#include "TimeSheet.h"

namespace lab3
{
    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
        : mCount(0)
        , mMaxEntries(maxEntries)
        , mTotalTime(0)
    {
        mTimes = new unsigned int[maxEntries];
        memset(mTimes, 0, sizeof(int) * maxEntries);
        mName = name;
    }

    TimeSheet::TimeSheet(const TimeSheet& other)
        : mCount(other.mCount)
        , mMaxEntries(other.mMaxEntries)
        , mTotalTime(other.mTotalTime)
        , mName(other.mName)
    {
        mTimes = new unsigned int[mMaxEntries];
        memcpy(mTimes, other.mTimes, sizeof(unsigned int) * mMaxEntries);
    }

    TimeSheet::~TimeSheet()
    {
        delete[] mTimes;
    }

    TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
    {
        if (mTimes == rhs.mTimes)
        {
            return *this;
        }
        
        delete[] mTimes;

        mCount = rhs.mCount;
        mMaxEntries = rhs.mMaxEntries;
        mTotalTime = rhs.mTotalTime;
        mName = rhs.mName;

        mTimes = new unsigned int[rhs.mMaxEntries];
        memcpy(mTimes, rhs.mTimes, sizeof(unsigned int) * mMaxEntries);

        return *this;
    }

    void TimeSheet::AddTime(int timeInHours)
    {
        if (timeInHours < 1 || timeInHours > 10 || mCount >= mMaxEntries)
        {
            return;
        }

        mTimes[mCount++] = timeInHours;
        mTotalTime += timeInHours;
    }

    int TimeSheet::GetTimeEntry(unsigned int index) const
    {
        if (index >= mCount)
        {
            return -1;
        }

        return mTimes[index];
    }

    int TimeSheet::GetTotalTime() const
    {
        return mTotalTime;
    }

    float TimeSheet::GetAverageTime() const
    {
        if (mTotalTime == 0)
        {
            return 0.0;
        }
        
        return mTotalTime / (float)mCount;
    }

    float TimeSheet::GetStandardDeviation() const
    {
        if (mCount == 0) 
        {
            return 0.0;
        }

        unsigned int squaredSum = 0;

        for (size_t i = 0; i < mCount; ++i) 
        {
            squaredSum += mTimes[i] * mTimes[i];
        }

        float average = GetAverageTime();
        float deviation = squaredSum / (float)mCount - average * average;

        return sqrt(deviation);
    }

    const std::string& TimeSheet::GetName() const
    {
        return mName;
    }
}
