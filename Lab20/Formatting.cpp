/* Formatting.cpp
   Jay-Mark Pascua
   CS 201
   03/25/2020
   Prints table of the values of cosine function
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <math.h>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::ostringstream;
using std::setw;
using std::setprecision;
using std::right;
using std::fixed;

vector <double> degreesToRadians(int degrees);

int main()
{
    ostringstream oss1;

    int degrees = 0;
    for (auto x : degreesToRadians(180))
    {
        cout << fixed << setw(3) << degrees << "\t" << setprecision(8) << setw(12) << cos(x) << endl;
            degrees += 5;
    }

}