/* floating_point.cpp
   Jay-Mark Pascua
   CS 201
   03/23/2020
   Useful trig functions
*/

#include "floating_point.h"

vector<double> degreesToRadians(int degrees) {

    vector<double> radians;

    for (int degree = 0; degree <= degrees; degree+=5)
    {
        double rad = degree * (M_PI / 180);
        radians.push_back(rad);
        vector<double> radians;
    }
    return radians;
}