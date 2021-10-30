#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
	Student();
	Student(string first, string last, float quiz1score, float quiz2score, float quiz3score, float quiz4score, float exam1score, float exam2score, float finalProject);
	string getFirstName();
	string getLastName();
	void getQuizScores(); //used to test if the data was being taken from the file properly
	void getExamScores(); //used to test if the data was being taken from the file properly
	float getFinalProjectScore(); //used to test if data was being taken from file properly
	bool AcquireData(ifstream& fin); 
	bool PrintData(ostream& cout);
	float CourseAverage();
	bool DisplayCourseAverage(ostream& cout);
	string LetterGrade();
private:
	string firstName;
	string lastName;
	float quiz1;
	float quiz2;
	float quiz3;
	float quiz4;
	float exam1;
	float exam2; 
	float finalProjectScore;
};

void InsertionSortVector(vector<Student>& studentList);

#endif
