//class header file

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Abdugram
{
private:
	string stat1, name, image;
	int age, fcnt;

public:

	Abdugram();
	void setStatus(string w);
	void setName(string x);
	void setPP(string y);
	void setAge(int z);
	string getName();
	string getStatus();
	string getPP();
	int getAge();
	void newAcc();
	void newStatus();
	void addAcc();
	void loginAcc();

	~Abdugram();
};
