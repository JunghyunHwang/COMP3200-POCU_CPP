#pragma once

#include <memory>

namespace test
{
	class MyString
	{
		friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
	public:
		MyString(const char* str);
		~MyString() = default;
		MyString(const MyString& other);
		MyString& operator=(const MyString& rhs);

		size_t GetLength() const;
		const char* GetCString() const;

	private:
		enum { CAPACITY = 64 };
		std::unique_ptr<char[]> mStr;
		size_t mSize;
		size_t mCapacity;
	};
}
