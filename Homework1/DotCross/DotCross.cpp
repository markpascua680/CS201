/* DotCross.cpp
   Jay-Mark Pascua
   CS 201
   01/31/2020
   Calculates the dot product and cross product of a 3-component vector
*/

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;

int main()
{
    double ax;
    double ay; // Vector A points
    double az;

    double bx;
    double by; // Vector B points
    double bz;

    // VECTOR A POINTS USER INPUT 
    cout << "Enter x value for Vector A: ";
    cin >> ax;
    cout << "Enter y value for Vector A: ";
    cin >> ay;
    cout << "Enter z value for Vector A: ";
    cin >> az; 
    cout << "Vector A floating points: (" << ax << ", " << ay << ", " << az << ")" << endl;


    // VECTOR B POINTS USER INPUT
    cout << "Enter x value for Vector B: ";
    cin >> bx;
    cout << "Enter y value for Vector B: ";
    cin >> by;
    cout << "Enter z value for Vector B: ";
    cin >> bz;
    cout << "Vector B floating points: (" << bx << ", " << by << ", " << bz << ")" << endl;


    // DOT PRODUCT CALCULATION
    double dotx = ax * bx;
    double doty = ay * by;
    double dotz = az * bz;
    cout << "\nDot product of vectors A and B: " << dotx + doty + dotz << endl;


    // CROSS PRODUCT CALCULATION
    double cx = (ay * bz) - (az * by);
    double cy = (az * bx) - (ax * bz);
    double cz = (ax * by) - (bx * ay);

    cout << "Cross product of vectors A and B: (" << setprecision(5) << cx << ", " << cy << ", " << cz << ")";


    return 0;
}