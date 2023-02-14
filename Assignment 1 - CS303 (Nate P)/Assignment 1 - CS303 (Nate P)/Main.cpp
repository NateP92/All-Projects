//Assignment 1 for CS 303; Authored by Nate Purcell
//Due 13 Feb 2023
#include <iostream>
#include <array>
#include <fstream>
#include "MyArray.h"
using namespace std;

int main()
{
	//Var Declarations and File Readers
	int myArray[15] {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int tempInt;
	int inputInt, returnInt, indexInt;
	int tempIndex=0;
	int ctr = 0;
	ifstream fin;

	//Read items into array from the file
	fin.open("ArrayInts.txt");
	while (fin.good())
	{
		fin.clear();
		fin >> tempInt;
		myArray[ctr] = tempInt;
		ctr++;
	}
	fin.close();

	//Initial output to tell user the numbers in array
	cout << "Greetings, your array has already been loaded with integers.";
	outputArray(myArray);
	cout << endl;

	//Ask User to Check for an Integer
	cout << "Please enter an integer and we will check to see if it is in the stored array :)" << endl;
	cin >> inputInt;
	returnInt = doesExist(myArray, inputInt);
	outputArray(myArray);

	//Replaces a number at a particular index
	cout << "Please provide the index of a number to change in the stored array." << endl;
	cin >> indexInt;
	cout << "Please provide the number you would like to place at that index." << endl;
	cin >> inputInt;
	returnInt = insertInt(myArray, indexInt, inputInt);
	outputArray(myArray);

	//Add an integer to the end off the array
	cout << "Lets add an integer to our array, please provide a number to add." << endl;
	cin >> inputInt;
	addInt(myArray, inputInt);
	outputArray(myArray);

	//Replaces an int at a specific index with a 0
	cout << "For our last operation, pleaes provide an index in the array, and the value at that index" << endl
		<< " will be replaced with a 0." << endl;
	cin >> indexInt;
	replaceOrRemove(myArray, indexInt);
	outputArray(myArray);
	return 0;
}