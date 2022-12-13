#pragma once

#include <memory>

namespace test
{
	class Vector
	{
	public:
		Vector() = delete;
		Vector(int x, int y);
		Vector(const Vector& other) = default;
		~Vector() = default;

		Vector& operator=(const Vector& rhs) = default;

		int GetX() const;
		int GetY() const;
		void DoMagic(std::shared_ptr<Vector> other);

	private:
		int mX;
		int mY;
	};
}
