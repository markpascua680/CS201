/* floating_point_main.cpp
   Jay-Mark Pascua
   CS 201
   03/23/2020
   Useful trig functions
*/

#include <iostream>
#include <vector>

#include "floating_point.h"

int main()
{
	/*
	std::vector<int> v{ 1, 2, 3, 4, 5 };
	for (size_t i = 2; i < v.size(); ++i) { // Unsigned int
		++v[i];
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl << std::endl;
	*/

	cout << "Degree, Cosine, Sin" << endl;
	
	int degree = 0;
	for (auto x : degreesToRadians(360))
	{
		double c = cos(x);
		double s = sin(x);
		cout << degree << ", "<< c << ", " << s << endl;
		degree++;
	}

	return 0;
}