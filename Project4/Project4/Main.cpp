#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;
int main() 
{
	//Var Declarations
	vector<Student> studentList;
	int numStudents;
	Student student1;

	//Take data from Project4Data.txt and place the information into the student1 object. After object is constructed, push it back into the studentList vector
	//cout << "Opening file.." << endl;
	//ifstream fin;
	//fin.open("Program4Data.txt");
	/*fin >> numStudents;*/
	cout << "Taking in data..." << endl;
	//student1.AcquireData(fin);
	//fin.close();
	TakeData(studentList);
	for (int i = 0; i < studentList.size(); i++)
	{
		cout << "Student's first name is " << studentList.at(i).getFirstName() << endl;
		cout << "Student's last name is " << studentList.at(i).getLastName() << endl;
		cout << "Student's quiz scores are: " << endl;
		studentList.at(i).getQuizScores();
		cout << "Student's exam scores are: " << endl;
		studentList.at(i).getExamScores();
		cout << "Student's final project scores is: " << studentList.at(i).getFinalProjectScore() << endl;
	}

	return 0;
}