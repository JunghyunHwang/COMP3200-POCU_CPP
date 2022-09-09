#pragma once
#include <cassert>

namespace assignment1
{
	class MyString
	{
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();
	private:
		void strCopy(char* dest, const char* origin)
		{
			assert(dest != nullptr);
			assert(origin != nullptr);

			char* pDest = dest;
			const char* pOrigin = origin;

			while (*pOrigin != '\0')
			{
				*pDest++ = *pOrigin++;
			}

			*pDest = '\0';
		}

		bool equals(const char* str1, const char* str2) const
		{
			while (*str1 != '\0' && *str1 == *str2)
			{
				++str1;
				++str2;
			}

			if (*str1 != '\0')
			{
				return false;
			}

			return true;
		}
	private:
		const int DEFAULT_CAPACITY = 20;
		const unsigned int ALPHA_MASK = 1 << 5;
		char* mStr;
		int mCount;
		int mCapacity;
	};
}
