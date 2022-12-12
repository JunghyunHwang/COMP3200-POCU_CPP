#pragma once

namespace test
{
	class Vector
	{
	public:
		Vector(int x, int y);
		~Vector() = default;
		inline int GetX() const;
		inline int GetY() const;

		bool operator==(const Vector& rhs) const;

	private:
		int mX;
		int mY;
	};

	inline int Vector::GetX() const
	{
		return mX;
	}

	inline int Vector::GetY() const
	{
		return mY;
	}
}
