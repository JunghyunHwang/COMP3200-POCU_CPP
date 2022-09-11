#include <iostream>
#include <cassert>
#include <cstring>

#include "MyString.h"

using namespace std;
using namespace assignment1;

void testConstructor();
void testCopyConstructor();
void testAppend();
void testEquals();
void testSubstitute();
void testPlusOperator();
void testReverse();
void testIndexOf();
void testLastIndexOf();
void testInterleave();
void testRemoveAt();
void testPadLeft();
void testPadRight();
void testSwitchCase();

int main()
{
	testConstructor();
	testAppend();
	testCopyConstructor();
	testEquals();
	testSubstitute();
	testPlusOperator();
	testReverse();
	testIndexOf();
	testLastIndexOf();
	testInterleave();
	testRemoveAt();
	testSwitchCase();

	cout << "No prob" << endl;

	return 0;
}

void testConstructor()
{
	MyString str1("POCU");

	assert(str1.GetLength() == 4);
	assert(strcmp(str1.GetCString(), "POCU") == 0);

	MyString str2("Give me the beat I ride it like a jetski");

	assert(str2.GetLength() == 40);
	assert(strcmp(str2.GetCString(), "Give me the beat I ride it like a jetski") == 0);
}

void testAppend()
{
	MyString str1("POCU");

	assert(str1.GetLength() == 4);
	assert(strcmp(str1.GetCString(), "POCU") == 0);

	str1.Append("DA");

	assert(str1.GetLength() == 6);
	assert(strcmp(str1.GetCString(), "POCUDA") == 0);

	str1.Append(" Season change and our love went cold");

	assert(str1.GetLength() == 43);
	assert(strcmp(str1.GetCString(), "POCUDA Season change and our love went cold") == 0);
}

void testCopyConstructor()
{
	MyString str1("POCU");
	MyString str2(str1);

	assert(str1.GetLength() == 4);
	assert(strcmp(str1.GetCString(), "POCU") == 0);

	assert(str2.GetLength() == 4);
	assert(strcmp(str2.GetCString(), "POCU") == 0);

	str1.Append("DAT");

	assert(str1.GetLength() == 7);
	assert(strcmp(str1.GetCString(), "POCUDAT") == 0);

	assert(str2.GetLength() == 4);
	assert(strcmp(str2.GetCString(), "POCU") == 0);
}

void testEquals()
{
	MyString str1("Hi My name is...");
	MyString str2("Hi My name is...");

	assert(str1 == str2);

	str1.RemoveAt(str1.GetLength() - 1);
	str1.Append(",");

	assert(!(str1 == str2));
}

void testSubstitute()
{
	MyString str1("Seaon change and our love went cold");
	MyString str2("Feed the flame");

	assert(strcmp(str1.GetCString(), str2.GetCString()) != 0);

	str2 = str1;

	assert(strcmp(str1.GetCString(), str2.GetCString()) == 0);
}

void testPlusOperator()
{
	MyString str1("Swim good swim good");
	MyString str2(" I got no worries all good It's so blurry all blurry all blurry all blurry");
	MyString str3 = str1 + str2;

	assert(strcmp(str3.GetCString(), "Swim good swim good I got no worries all good It's so blurry all blurry all blurry all blurry") == 0);
}

void testReverse()
{
	MyString str1("Swim");

	str1.Reverse();

	assert(strcmp(str1.GetCString(), "miwS") == 0);
}

void testIndexOf()
{
	MyString str1("Season change and our love went cold");
	string str(str1.GetCString());

	size_t result = str.find("");
	result = str.find("z");

	assert(str1.IndexOf("son") == str.find("son"));
	assert(str1.IndexOf("n ") == str.find("n "));
	assert(str1.IndexOf(" a") == str.find(" a"));
	assert(str1.IndexOf("Hello") == str.find("Hello"));
	assert(str1.IndexOf("Season change and our love went cold") == str.find("Season change and our love went cold"));
	assert(str1.IndexOf("") == str.find(""));
}

void testLastIndexOf()
{
	MyString str1("old sold cold hold");
	string str(str1.GetCString());

	assert(str1.LastIndexOf("old") == str.rfind("old"));
	assert(str1.LastIndexOf("sold") == str.rfind("sold"));
	assert(str1.LastIndexOf("old ") == str.rfind("old "));
	assert(str1.LastIndexOf(" old") == str.rfind(" old"));
	assert(str1.LastIndexOf("d") == str.rfind("d"));
	assert(str1.LastIndexOf("old sold cold hold") == str.rfind("old sold cold hold"));
	assert(str1.LastIndexOf("") == str.rfind(""));
}

void testInterleave()
{
	MyString s1("Hello");
	s1.Interleave(" World");

	assert(strcmp(s1.GetCString(), "H eWlolrold") == 0);

	s1.Interleave("");
	assert(strcmp(s1.GetCString(), "H eWlolrold") == 0);

	s1.Interleave("i");
	assert(strcmp(s1.GetCString(), "Hi eWlolrold") == 0);

	MyString s2("Season change and our love went cold");

	s2.Interleave("     ");
	assert(strcmp(s2.GetCString(), "S e a s o n change and our love went cold") == 0);
}

void testRemoveAt()
{
	MyString s1("You didn't love when you had me");
	
	assert(s1.RemoveAt(200) == false);

	assert(s1.RemoveAt(8));
	assert(strcmp(s1.GetCString(), "You didnt love when you had me") == 0);

	assert(s1.RemoveAt(s1.GetLength() - 1));
	assert(strcmp(s1.GetCString(), "You didnt love when you had m") == 0);
	
	assert(s1.RemoveAt(0));
	assert(strcmp(s1.GetCString(), "ou didnt love when you had m") == 0);

	assert(s1.RemoveAt(s1.GetLength() - 1));
	assert(strcmp(s1.GetCString(), "ou didnt love when you had ") == 0);
	
	assert(s1.RemoveAt(0));
	assert(strcmp(s1.GetCString(), "u didnt love when you had ") == 0);

	assert(s1.RemoveAt(s1.GetLength() - 1));
	assert(strcmp(s1.GetCString(), "u didnt love when you had") == 0);

	assert(s1.RemoveAt(0));
	assert(strcmp(s1.GetCString(), " didnt love when you had") == 0);
}

void testPadLeft()
{
	MyString s1("Hello");

	s1.PadLeft(2);
	assert(strcmp(s1.GetCString(), "Hello") == 0);

	s1.PadLeft(5);
	assert(strcmp(s1.GetCString(), "Hello") == 0);

	s1.PadLeft(6);
	assert(strcmp(s1.GetCString(), " Hello") == 0);

	s1.PadLeft(10);
	assert(strcmp(s1.GetCString(), "     Hello") == 0);

	s1.PadLeft(11, '-');
	assert(strcmp(s1.GetCString(), "-     Hello") == 0);

	s1.PadLeft(20, '*');
	assert(strcmp(s1.GetCString(), "*********-     Hello") == 0);

	s1.PadLeft(21, '/');
	assert(strcmp(s1.GetCString(), "/*********-     Hello") == 0);
}

void testPadRight()
{
	MyString s1("Hello");

	s1.PadRight(2);
	assert(strcmp(s1.GetCString(), "Hello") == 0);

	s1.PadRight(8);
	assert(strcmp(s1.GetCString(), "Hello   ") == 0);

	MyString s2("World");

	s2.PadRight(3, '-');
	assert(strcmp(s2.GetCString(), "World") == 0);

	s2.PadRight(7, '-');
	assert(strcmp(s2.GetCString(), "World--") == 0);
}

void testSwitchCase()
{
	MyString s1("Hello");
	
	s1.ToUpper();
	assert(strcmp(s1.GetCString(), "HELLO") == 0);

	s1.ToLower();
	assert(strcmp(s1.GetCString(), "hello") == 0);

	MyString s2("H1e2l3l4O5");

	s2.ToUpper();
	assert(strcmp(s2.GetCString(), "H1E2L3L4O5") == 0);

	s2.ToLower();
	assert(strcmp(s2.GetCString(), "h1e2l3l4o5") == 0);
}
