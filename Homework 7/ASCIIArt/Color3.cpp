// Color3.cpp
// Jay-Mark Pascua
// Implementation for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Color3.h"
#include "Image3.h"

using std::setw;

int main() {
	Image3 image(3, 2);
	if (!image.loadPPM("parrot.ppm")) {
		std::cout << "Error opening file" << std::endl;
	}
	else
	{

	}

	return 0;
}

// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue) {
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}

Color3::Color3()
	: r(0), g(0), b(0)
{ }

Color3::Color3(int R, int G, int B) {
	r = (unsigned char)saturate(R, 255);
	g = (unsigned char)saturate(G, 255);
	b = (unsigned char)saturate(B, 255);
}

int Color3::weightedSum() const {
	// Implement Y = 0.2126R + 0.7152G + 0.0722B
	// Ensure values are inside the range 0 to 255
	int Y = saturate((0.2126 * r) + (0.7152 * g) + (0.0722 * b), 255);
	return Y;
}

char Color3::asciiValue() const {
	// Use at least 16 characters, sort these from dark to light
	// or light to dark and then map the weightedSum() to the range
	// 0 to 15. Please pick your own characters
	const char values[] = " _,.;:({|/i1lQM0";
	unsigned darkness = weightedSum() / 15 % 15;
	return values[darkness];
}

// Stream Operators for input and output

std::ostream& operator<<(std::ostream& ostr, const Color3& color) {
	ostr << setw(3) << (int)color.r << " ";
	ostr << setw(3) << (int)color.g << " ";
	ostr << setw(3) << (int)color.b << " ";
	return ostr;
}

std::istream& operator>>(std::istream& istr, Color3& color) {
	// Implement your own input for a Color3
	int r;
	int g;
	int b;
	istr >> r;
	istr >> g;
	istr >> b;
	color.r = saturate(r, 255);
	color.g = saturate(g, 255);
	color.b = saturate(b, 255);
	return istr;
}