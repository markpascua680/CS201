/* MilesKm.cpp
   Jay-Mark Pascua
   CS 201
   01/31/2020
   Converts miles into kilometers
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    double mi;
    double km;
    cout << "// MILES TO KILOMETERS CONVERTER \\\\\n" << endl;
    cout << "Enter a positive number of miles to convert into kilometers: ";
    cin >> mi;

    km = 1.609 * mi; // Converts miles to kilometers

    cout << mi << " Miles = " << km << " kilometers";





    return 0;
}