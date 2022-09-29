#include <iostream>
#include <cassert>

#include "Point.h"
#include "PolyLine.h"
#include "Test.h"

namespace testcase
{
	void TestOfficial()
	{
		lab4::Point p1(2, 3);
		lab4::Point p2(-1, 4);

		lab4::Point p3 = p1 + p2;

		assert(std::abs(p3.GetX() - 1) <= EPSILON);
		assert(std::abs(p3.GetY() - 7) <= EPSILON);

		lab4::Point p4 = p2 - p1;

		assert(std::abs(p4.GetX() - (-3)) <= EPSILON);
		assert(std::abs(p4.GetY() - 1) <= EPSILON);

		float dotProduct = p1.Dot(p2);

		assert(std::abs(dotProduct - 10) <= EPSILON);

		lab4::Point p5 = p1 * 5;

		assert(std::abs(p5.GetX() - 10) <= EPSILON);
		assert(std::abs(p5.GetY() - 15) <= EPSILON);

		lab4::Point p6 = 2 * p2;

		assert(std::abs(p6.GetX() - (-2)) <= EPSILON);
		assert(std::abs(p6.GetY() - 8) <= EPSILON);

		/* ----------------------- */

		lab4::PolyLine pl1;
		pl1.AddPoint(1, 2);
		pl1.AddPoint(3, 2);
		pl1.AddPoint(5, 5);
		pl1.AddPoint(-2, 4);
		pl1.AddPoint(4, -1);
		pl1.AddPoint(6, 4);

		bool bRemoved = pl1.RemovePoint(4);

		assert(bRemoved);

		lab4::Point minP(0.f, 0.f);
		lab4::Point maxP(0.f, 0.f);

		pl1.TryGetMinBoundingRectangle(&minP, &maxP);

		assert(minP.GetX() == -2);
		assert(minP.GetY() == 2);
		assert(maxP.GetX() == 6);
		assert(maxP.GetY() == 5);
	}

	void TestPolyLineOperator()
	{
		lab4::PolyLine pl1;

		pl1.AddPoint(new lab4::Point(1, 1));
		pl1.AddPoint(new lab4::Point(2, 2));
		pl1.AddPoint(new lab4::Point(3, 3));
		pl1.AddPoint(new lab4::Point(4, 4));
		pl1.AddPoint(new lab4::Point(5, 5));

		assert(pl1.RemovePoint(5) == false);

		lab4::PolyLine pl2;

		pl2 = pl1;

		for (size_t i = 0; i < 5; ++i)
		{
			assert(pl1[i]->GetX() == i + 1);
			assert(pl1[i]->GetY() == i + 1);
		}
	}

	void TestPointOperator()
	{
		const lab4::Point p1(2, 2);
		const lab4::Point p2(1, 1);
		lab4::Point result = p1 + p2;

		assert(result.GetX() == 3);
		assert(result.GetY() == 3);

		result = result - p2;
		assert(result.GetX() == 2);
		assert(result.GetY() == 2);

		result = result - p1 - p2;
		assert(result.GetX() == -1);
		assert(result.GetY() == -1);

		assert(result.Dot(p1) == -4.0);

		result = result * -2;
		assert(result.GetX() == 2);
		assert(result.GetY() == 2);
	}

	void TestMinBoundingRectangle()
	{
		lab4::PolyLine pl1;

		pl1.AddPoint(1, 2);
		pl1.AddPoint(-3, -1);
		pl1.AddPoint(new lab4::Point(0, 0));

		lab4::Point min(0, 0);
		lab4::Point max(0, 0);

		pl1.TryGetMinBoundingRectangle(&min, &max);

		assert(min.GetX() == -3);
		assert(min.GetY() == -1);

		assert(max.GetX() == 1);
		assert(max.GetY() == 2);
	}
}