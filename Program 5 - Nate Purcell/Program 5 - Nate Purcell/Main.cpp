//Program 5 || Nate Purcel || CS 201-R || Fall Semester 2021

#include "Media.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	Media* mediaList[200];
	int counter = 0;
	char random;
	fstream fin;
	fstream vfout;
	vfout.open("VideoAccounts.txt");
	fstream afout;
	afout.open("AudioAccounts.txt");
	fin.open("Program5Data.txt");
	fin >> random;
	while (fin.good())
	{
		if (random == 'V')
		{
			Video* vidptr;
			Video v("userResolution", "userDescriptor", "userSpec");
			v.ReadData(fin);
			vidptr = &v;
			mediaList[counter] = vidptr;
			v.WriteData(vfout);

		}
		if (random == 'A')
		{
			Audio* audptr;
			Audio a("userDescriptor", "userSpecification");
			a.ReadData(fin);
			audptr = &a;
			mediaList[counter] = audptr;
			a.WriteData(afout);
		}
		fin >> random;
		cout << endl;
		counter++;
	}
	fin.close();
	vfout.close();
	afout.close();
	return 0;
}