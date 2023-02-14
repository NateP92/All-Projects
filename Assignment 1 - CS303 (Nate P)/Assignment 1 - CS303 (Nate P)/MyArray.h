//Assignment 1 for CS 303 by Nate Purc cell
#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
#include <array>
#include <fstream>
using namespace std;

//This function checks if an integer exists in the array and returns the index of the number if it is present
int doesExist(int a[], int index);

//This function will modify the value of an int in the array at the index provided
int insertInt(int a[], int index, int num);

//This function simply adds an integer to the end of the array
void addInt(int a[],int newInt);

//This function intakes an index and an array of integers, and replaces the item at the endex with a 0.
void replaceOrRemove(int a[], int index);

//Reads the items in my array
void outputArray(int a[]);
#endif
