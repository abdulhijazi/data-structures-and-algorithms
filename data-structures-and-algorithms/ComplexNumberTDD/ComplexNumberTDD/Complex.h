// This is the declaration of class Complex

#pragma once
#include <string>

class Complex
{
private:
	double a, b; //a is real number b is imaginary

public:
	Complex(); //implementation of these functions in cpp file
	void addAB(double a1, double b1, double a2, double b2);
	void subtractAB(double a1, double b1, double a2, double b2);
	std::string printAB();
};

