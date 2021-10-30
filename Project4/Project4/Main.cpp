#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Student.h"
using namespace std;
int main() 
{
	//Var Declarations
	vector<Student> studentList;
	int numStudents;
	
	//Take data from Project4Data.txt and place the information into the student1 object. After object is constructed, push it back into the studentList vector
	ifstream fin;
	fin.open("Program4Data.txt");
	fin >> numStudents;
	for (int i = 0; i < numStudents; i++)
	{
		Student student1;
		student1.AcquireData(fin);
		studentList.push_back(student1);
	}
	fin.close();

	//Sort by Course Average
	InsertionSortVector(studentList);

	//Output new list to screen
	for (int i = 0; i < numStudents; i++)
	{
		studentList.at(i).PrintData(cout);
	}

	return 0;
}
