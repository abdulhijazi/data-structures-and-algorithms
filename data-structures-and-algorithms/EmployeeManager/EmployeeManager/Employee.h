// class Employee header file
// only contains the function names
#pragma once
#include <string>
using namespace std;
class Employee
{
private:
	string first, last;
	int salary;

public:
	Employee(); //only the names of the functions are listed inside the header, implementation is in a seperate .cpp file
	void setFirst(string f);
	void setLast(string l);
	void setSalary(int s);
	string getFirst();
	string getLast();
	int getSalary();
};