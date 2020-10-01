//class implementation

#include "Abdugram.h"


Abdugram::Abdugram()
{
	int fcnt = 0;
	string name = " ";
	int age = 0;
	string image = " ";
	string stat1 = " ";
}
void Abdugram::setStatus(string stat) {
	stat1 = stat;
}
void Abdugram::setName(string nam)
{
	name = nam;
}
void Abdugram::setPP(string img1)
{
	image = img1;
}
void Abdugram::setAge(int years)
{
	age = years;
}
string Abdugram::getName() {
	return name;
}
string Abdugram::getStatus() {
	return stat1;
}
string Abdugram::getPP() {
	return image;
}
int Abdugram::getAge() {
	return age;
}
void Abdugram::newAcc() {
	string NameIn;
	string ImageIn;
	int AgeIn;
	cout << "Enter the following information about yourself:\nName" << endl;
	cin >> NameIn;
	cout << "Age" << endl;
	cin >> AgeIn;
	cout << "Profile picture URL" << endl;
	cin >> ImageIn;
	setName(NameIn);
	setPP(ImageIn);
	setAge(AgeIn);

}
void Abdugram::newStatus() //called in switch case to overwrite current status
{
	string newstatus;
	cout << "Type in your status:" << endl;
	cin >> newstatus;
	setStatus(newstatus);
}
void Abdugram::addAcc() //increases friend count if searchname function finds acnt name
{
	cout << "Number of friends: " << ++fcnt << endl;
}
void Abdugram::loginAcc() //outputs current profile info is searchname finds login name
{
	cout << "Welcome " << name << endl;
	cout << "Status: " << stat1 << endl;
	cout << "Friends: " << fcnt << endl;

}


Abdugram::~Abdugram()
{
}
