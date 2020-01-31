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
    int ax;
    int ay; // Vector A points
    int az;

    int bx;
    int by; // Vector B points
    int bz;

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



    return 0;
}