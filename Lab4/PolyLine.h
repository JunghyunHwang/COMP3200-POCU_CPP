#pragma once

#include <cassert>
#include "Point.h"

namespace lab4
{
	enum
	{
		POINTS_CAPACITY = 10
	};

	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
		PolyLine& operator=(const PolyLine& rhs);

	private:
		const Point* mPoints[POINTS_CAPACITY];
		unsigned int mSize;
	};
}