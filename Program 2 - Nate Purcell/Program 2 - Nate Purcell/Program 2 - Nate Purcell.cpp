// Program 2 - Nate Purcell.cpp | CS 201-R | T/R 11:30-12:45 | Program 2 Due date: 26 Sep 21

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

//Function Declarations

int main()
{
	//Var Declarations
	int player1score = 0;
	int player2score = 0;
	int roundCounter = 1;

	//Greeting to user
	cout << "-----------------------------------" << endl;
	cout << "***Welcome to Sorry Board Game***" << endl;
	cout << "***Game will be played with 2 players***" << endl;
		

	//While loop to iterate each round and add any score gained to each score
	while ((player1score != 30) && (player2score != 30))
	{
		cout << endl;
	}

}

//Functions
//(1) Need a function using rand() to generate a random number between 1 and 12 (use %)
//(2) A function to play a round would be helpful
//		- While loop that iterates 
//(3) I can keep track of the points in main so that way they don't ever get messed up and then always pass by value
//
