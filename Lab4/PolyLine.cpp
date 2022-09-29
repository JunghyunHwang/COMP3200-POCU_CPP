#include <iostream>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mSize(other.mSize)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			mPoints[i] = new Point(*other.mPoints[i]);
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			delete mPoints[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		
		for (size_t i = 0; i < mSize; ++i)
		{
			delete mPoints[i];
		}

		mSize = rhs.mSize;

		for (size_t i = 0; i < mSize; ++i)
		{
			mPoints[i] = new Point(*rhs.mPoints[i]);
		}

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= POINTS_CAPACITY)
		{
			return false;
		}

		mPoints[mSize++] = new Point(x, y);

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= POINTS_CAPACITY)
		{
			return false;
		}

		mPoints[mSize++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}

		delete mPoints[i];

		--mSize;

		for (size_t idx = i; idx < mSize; ++idx)
		{
			mPoints[idx] = mPoints[idx + 1];
		}

		mPoints[mSize] = nullptr;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		assert(outMin != nullptr);
		assert(outMax != nullptr);

		if (mSize == 0)
		{
			return false;
		}
		else if (mSize == 1)
		{
			*outMin = *mPoints[0];
			*outMax = *mPoints[0];

			return true;
		}

		float minX = std::numeric_limits<float>::max();
		float minY = std::numeric_limits<float>::max();

		float maxX = std::numeric_limits<float>::lowest();
		float maxY = std::numeric_limits<float>::lowest();

		for (size_t i = 0; i < mSize; ++i)
		{
			const float POINT_X = mPoints[i]->GetX();
			const float POINT_Y = mPoints[i]->GetY();

			maxX = POINT_X > maxX ? POINT_X : maxX;
			maxY = POINT_Y > maxY ? POINT_Y : maxY;

			minX = POINT_X < minX ? POINT_X : minX;
			minY = POINT_Y < minY ? POINT_Y : minY;
		}

		const Point minPoint(minX, minY);
		const Point maxPoint(maxX, maxY);

		*outMin = minPoint;
		*outMax = maxPoint;

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
		{
			return nullptr;
		}

		return mPoints[i];
	}
}