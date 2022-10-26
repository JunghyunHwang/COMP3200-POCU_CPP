#pragma once

namespace practice
{
	class Vector
	{
		friend Vector operator*(int lhs, const Vector& rhs);
	public:
		Vector(int x, int y);
		virtual ~Vector();

		inline int GetX() const;
		inline int GetY() const;

		Vector operator+(const Vector& rhs) const;
		Vector operator*(const Vector& rhs) const;
		Vector operator-(const Vector& rhs) const;

		Vector& operator++();
		Vector operator++(int);

		Vector& operator--();
		Vector operator--(int);

	private:
		int mX;
		int mY;
	};

	int Vector::GetX() const
	{
		return mX;
	}

	int Vector::GetY() const
	{
		return mY;
	}
}

