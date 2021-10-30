#include "Student.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
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
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
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

bool Student::PrintData(ostream& out) 
{
	return true;

}

//Calculates the student object's avg
float Student::CourseAverage()                                                       //FIX ME: ALL OF THESE FUNCTIONS ARE INCOMPLETE
{
	float courseAvg = 0;
	return courseAvg;
}
bool Student::DisplayCourseAverage()
{
	return true;
}
string Student::LetterGrade()
{
	string letterGrade;
	return letterGrade;
}

void TakeData(vector<Student>& studentList)
{
	ifstream fin;
	fin.open("Program4Data.txt");
	int randomNum;
	string first;
	string last;
	float quiz1score;
	float quiz2score;
	float quiz3score;
	float quiz4score;
	float exam1score;
	float exam2score;
	float finalProject;

	fin >> randomNum;
	while (fin.good())
	{
		fin >> first;
		fin >> last;
		fin >> quiz1score;
		fin >> quiz2score;
		fin >> quiz3score;
		fin >> quiz4score;
		fin >> exam1score;
		fin >> exam2score;
		fin >> finalProject;

		Student tempStudent(first, last, quiz1score, quiz2score, quiz3score, quiz4score, exam1score, exam2score, finalProject);
		studentList.push_back(tempStudent);
	}
}