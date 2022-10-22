#pragma once

class Point
{
public:
	Point();
	Point(const Point& other);
	~Point();

	int GetX() const;
	int GetY() const;
	static int GetCount();

private:
	int mX;
	int mY;
	static int mCount;
};
