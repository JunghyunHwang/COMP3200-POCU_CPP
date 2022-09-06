#include <iostream>
#include <cassert>
#include <cstring>

#include "MyString.h"

using namespace std;
using namespace assignment1;

void testConstructor();
void testCopyConstructor();
void testAppend();

int main()
{
	testConstructor();
	testAppend();
	testCopyConstructor();

	cout << "No prob" << endl;

	return 0;
}

void testConstructor()
{
	MyString str1("POCU");
	string cmp(str1.GetCString());

	assert(str1.GetLength() == 4);
	assert(cmp == "POCU");

	MyString str2("Give me the beat I ride it like a jectski");
	cmp = str2.GetCString();

	assert(str2.GetLength() == 41);
	assert(cmp == "Give me the beat I ride it like a jectski");
}

void testAppend()
{
	MyString str1("POCU");
	string cmp(str1.GetCString());

	assert(str1.GetLength() == 4);
	assert(cmp == "POCU");

	str1.Append("DA");
	cmp = str1.GetCString();

	assert(str1.GetLength() == 6);
	assert(cmp == "POCUDA");

	str1.Append(" Season change and our love went cold");
	cmp = str1.GetCString();

	assert(str1.GetLength() == 43);
	assert(cmp == "POCUDA Season change and our love went cold");
}

void testCopyConstructor()
{
	MyString str1("POCU");
	MyString str2(str1);
	string cmp1(str1.GetCString());
	string cmp2(str2.GetCString());

	assert(str1.GetLength() == 4);
	assert(cmp1 == "POCU");

	assert(str2.GetLength() == 4);
	assert(cmp2 == "POCU");

	str1.Append("DAT");
	cmp1 = str1.GetCString();

	assert(str1.GetLength() == 7);
	assert(cmp1 == "POCUDAT");

	assert(str2.GetLength() == 4);
	assert(cmp2 == "POCU");
}
