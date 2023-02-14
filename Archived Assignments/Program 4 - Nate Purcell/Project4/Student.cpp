#include "Student.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Default constructor
Student::Student()
{
	firstName = "";
	lastName = "";
	finalProjectScore = 0;
}

//Custom constructor
Student::Student(string first, string last, float quiz1score, float quiz2score, float quiz3score, float quiz4score, float exam1score, float exam2score, float finalProject)
{
	firstName = first;
	lastName = last;
	quiz1 = quiz1score;
	quiz2 = quiz2score;
	quiz3 = quiz3score;
	quiz4 = quiz4score;
	exam1 = exam1score;
	exam2 = exam2score;
	finalProjectScore = finalProject;
}

//Getters
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
void Student::getQuizScores()
{
	cout << "Quiz 1 score: " << quiz1 << endl;
	cout << "Quiz 2 score: " << quiz2 << endl;
	cout << "Quiz 3 score: " << quiz3 << endl;
	cout << "Quiz 4 score: " << quiz4 << endl;
}
void Student::getExamScores()
{
	cout << "Exam 1 score: " << exam1 << endl;
	cout << "Exam 2 score: " << exam2 << endl;
}
float Student::getFinalProjectScore() { return finalProjectScore; }

//Data collection member functions
bool Student::AcquireData(ifstream& fin)
{
	string first;
	string last;
	float quiz1score;
	float quiz2score;
	float quiz3score;
	float quiz4score;
	float exam1score;
	float exam2score;
	float finalProject;

	
	fin >> first;
	firstName = first;
	fin >> last;
	lastName = last;
	fin >> quiz1score;
	quiz1 = quiz1score;
	fin >> quiz2score;
	quiz2 = quiz2score;
	fin >> quiz3score;
	quiz3 = quiz3score;
	fin >> quiz4score;
	quiz4 = quiz4score;
	fin >> exam1score;
	exam1  = exam1score;
	fin >> exam2score;
	exam2 = exam2score;
	fin >> finalProject;
	finalProjectScore = finalProject;

	if (fin.good() == true)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Student::PrintData(ostream& cout) const 
{
	cout << left;
	cout << setw(20) << getFirstName();
	cout << setw(20) << getLastName();
	cout << setw(10) << DisplayCourseAverage(cout);
	cout << setw(5) << LetterGrade() << endl;
	if (cout.good() == true)
	{
		return true;
	}
	else { return false; }
}

//Calculates the student object's avg
float Student::CourseAverage()const                                                       
{
	float courseAvg;
	float quizAvg;
	float examAvg;

	quizAvg = ((quiz1 + quiz2 + quiz3 + quiz4) / 40) * 100;
	examAvg = ((exam1 + exam2) / 200) * 100;
	courseAvg = ((quizAvg * .35) + (examAvg * .35) + (finalProjectScore * .3));
	return courseAvg;
}

//Displays course avg but will only return a boolean
bool Student::DisplayCourseAverage (ostream& cout) const 
{
	float courseAverage = CourseAverage();
	
	cout << fixed << setprecision(1) << courseAverage;

	if (cout.good() == true)
	{
		return true;
	}
	else 
	{
		return false;
	}
}


string Student::LetterGrade()const 																	//FIX ME: ALL OF THE BELOW FUNCTIONS ARE INCOMPLETE
{
	string letterGrade;
	float courseAvg = CourseAverage();
	if (courseAvg >= 93)
	{
		letterGrade = "A";
	}
	else if (courseAvg >= 90 && courseAvg < 94)
	{
		letterGrade = "A-";
	}
	else if (courseAvg >= 87 && courseAvg < 90)
	{
		letterGrade = "B+";
	}
	else if (courseAvg >= 83 && courseAvg < 87)
	{
		letterGrade = "B";
	}
	else if (courseAvg >= 80 && courseAvg < 83)
	{
		letterGrade = "B-";
	}
	else if (courseAvg >= 77 && courseAvg < 80)
	{
		letterGrade = "C+";
	}
	else if (courseAvg >= 73 && courseAvg < 77)
	{
		letterGrade = "C";
	}
	else if (courseAvg >= 70 && courseAvg < 73)
	{
		letterGrade = "C-";
	}
	else if (courseAvg >= 67 && courseAvg < 70)
	{
		letterGrade = "D+";
	}
	else if (courseAvg >= 63 && courseAvg < 67)
	{
		letterGrade = "D";
	}
	else if (courseAvg >= 60 && courseAvg < 63)
	{
		letterGrade = "D-";
	}
	else if (courseAvg < 60)
	{
		letterGrade = "F";
	}
		return letterGrade;
}

bool operator>(Student lhs, Student rhs)
{
	float lhs_num = (lhs.CourseAverage());
	float rhs_num = (rhs.CourseAverage());
	return lhs_num > rhs_num;
}

void InsertionSortVector(vector<Student>& studentList)
{
	Student tempVal;
	int j;
	for (int i = 1; i < studentList.size(); i++)
	{
		j = i;
		while (j > 0 && studentList.at(j) > studentList.at(j - 1))
		{
			tempVal = studentList.at(j);
			studentList.at(j) = studentList.at(j - 1);
			studentList.at(j - 1) = tempVal;
			--j;
		}
	}
	return;
}