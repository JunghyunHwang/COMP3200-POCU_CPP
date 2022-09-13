#include <iomanip>
#include <string>

#include "Lab2.h"

#define OCT_WIDTH 12
#define DEC_WIDTH 11
#define HEX_WIDTH 9

using namespace std;

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        std::string trash;
        int number;

        // Print header
        out << setw(OCT_WIDTH) << "oct"
            << setw(DEC_WIDTH) << "dec"
            << setw(HEX_WIDTH) << "hex" << endl;

        out << setfill('-') << setw(OCT_WIDTH) << ""
            << " " << setfill('-') << setw(DEC_WIDTH - 1) << ""
            << " " << setfill('-') << setw(HEX_WIDTH - 1) << "" << endl;

        out << setfill(' ');

        while (!in.eof())
        {
            in >> number;

            if (in.fail())
            {
                in.clear();
                in >> trash;
            }
            else
            {
                out << setw(OCT_WIDTH) << oct << number
                    << setw(DEC_WIDTH) << dec << number
                    << setw(HEX_WIDTH) << uppercase << hex << number << endl;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {

    }
}
