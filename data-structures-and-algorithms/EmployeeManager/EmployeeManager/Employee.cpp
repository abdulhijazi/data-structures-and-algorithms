// class Employee implementation
// contains the definitions and initialization of the functions for class Employee
#include "Employee.h"
using namespace std;

Employee::Employee()
{
	string first = "No"; //without any input, all values are initialized to 0
	string last = "Name";
	int salary = 0;

}
void Employee::setFirst(string f) //sets employees first name
{
	first = f;
}
void Employee::setLast(string l) //sets employees last name
{
	last = l;
}
void Employee::setSalary(int s) //sets employees salary
{
	if (s > 0) //salary is whatever the user inputted as long it is greater than or equal to 0
		salary = s;
	else //anything negative will automatically be set to 0
		salary = 0;
}
string Employee::getFirst() //gets employees first name
{
	return first;
}
string Employee::getLast() //gets employees last name
{
	return last;
}
int Employee::getSalary() //gets employees salary
{
	return salary;
}