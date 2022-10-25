#pragma once

class Point
{
public:
	Point();
	Point(const Point& other);
	virtual ~Point();

	inline int GetX() const;
	inline int GetY() const;

private:
	int mX;
	int mY;
};
