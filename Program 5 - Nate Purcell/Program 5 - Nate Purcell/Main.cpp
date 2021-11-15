//Program 5 || Nate Purcel || CS 201-R || Fall Semester 2021

#include "Media.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	char random;
	fstream fin;
	fin.open("Program5Data.txt");
	fin >> random;
	Video v("userResolution", "userDescriptor", "userSpec");
	v.ReadData(fin);
	//v.setAccountName("Natty P");
	cout << "account name is " << v.getAccountName() << endl;
	cout << "account ID is " << v.getIdentifier() << endl;
	cout << "Time is " << v.getTimeInSeconds() << endl;;
	cout << "Resolution is " << v.getResolution() << endl;
	cout << "Format descriptor is " << v.getFormatDescriptor() << endl;
	cout << "Specification is " << v.getSpecification() << endl;
	fin.close();
	return 0;
}