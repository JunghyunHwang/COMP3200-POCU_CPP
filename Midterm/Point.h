#pragma once

class Point
{
public:
	Point(int x, int y);
	Point(const Point& other);
	~Point();

	inline int GetX() const;
	inline int GetY() const;

private:
	int mX;
	int mY;
};
