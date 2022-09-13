#include <fstream>

#include "lab2.h"

int main()
{
	std::ifstream fin;
	std::ofstream fout;

	fin.open("inputInt.txt");
	fout.open("resultInt.txt");
	{
		lab2::PrintIntegers(fin, fout);
	}
	fout.close();
	fin.close();


	fin.open("inputFloat.txt");
	fout.open("resultFloat.txt");
	{
		lab2::PrintMaxFloat(fin, fout);
	}
	fout.close();
	fin.close();

	return 0;
}