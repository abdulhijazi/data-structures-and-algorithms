// This is the implementation of the class Complex

#include "Complex.h"
#include <string>
using namespace std;

Complex::Complex() //automatically sets both to 1 when not initialized in main program
{
	a = 1;
	b = 1;
}

void Complex::addAB(double a1, double b1, double a2, double b2) //adds real and imaginary parts then sets the results to a and b respectively inside class
{
	a = a1 + a2;
	b = b1 + b2;
}

void Complex::subtractAB(double a1, double b1, double a2, double b2) //same as previous, but subtraction
{
	a = a1 - a2;
	b = b1 - b2;
}

string Complex::printAB() //outputs the complex number in (a+bi) format as a string
{
	string outAB;
	if (b >= 0)
		outAB = "(" + to_string(a) + "+" + to_string(b) + "i)";
	else
		outAB = "(" + to_string(a) + to_string(b) + "i)";
	return outAB;
}