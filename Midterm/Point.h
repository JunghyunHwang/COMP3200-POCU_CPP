#pragma once

class Point
{
public:
	Point(int x, int y);
	Point(const Point& other);
	~Point();

	static unsigned int mCount;

private:
	int mX;
	int mY;
};
