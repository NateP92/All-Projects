//Assignment 1 for CS 303 by Nate Purcell
#include <iostream>
#include <array>
#include <fstream>
#include "MyArray.h"
using namespace std;

//This function checks if an integer exists in the array and returns the index of the number if it is present
int doesExist(int a[], int num)
{
	int indexFound = -1;
	for (int i = 0; i < 15; i++)
	{
		if (a[i] == num)
		{
			indexFound = i;
			cout << "Your number was found at index " << indexFound << endl;
			return indexFound;
		}
	}

	if (indexFound == -1)
	{
		cout << "The integer you searched for is not in this array." << endl;
		return indexFound;
	}

	
};

//This function will modify the value of an int in the array at the index provided
int insertInt(int a[], int index, int num)
{
	try 
	{
		//Return old int
		int oldInt;
		oldInt = a[index];
		cout << "The old integer at index " << index << " was " << oldInt << "." << endl;

		//Update array and return new int;
		a[index] = num;
		cout << "The number at index " << index << " has been updated to " << num << "." << endl;
	}
	catch (out_of_range& ex) {
		cout << "Out of range exception has occurred." << endl;
		cout << ex.what() << endl;
	}
	return num;
};

//This function simply adds an integer to the end of the array
void addInt(int a[],int newInt)
{
	try 
	{
	int i = 0;
		while (a[i] != 0)
		{
			if (a[i + 1] == 0)
			{ 
				a[i + 1] = newInt;
				return;
			} 
		i++;
		}
	} catch (out_of_range& ex) {
	cout << "Out of range exception has occurred." << endl;
	cout << ex.what() << endl;
}
	return;
};

//This function intakes an index and an array of integers, and replaces the item at the endex with a 0.
void replaceOrRemove(int a[], int index)
{
	a[index] = 0;
	return;
};

//Reads the items in my array
void outputArray(int a[])
{
	cout << endl << "Reading all items in your array..." << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
	return;
};