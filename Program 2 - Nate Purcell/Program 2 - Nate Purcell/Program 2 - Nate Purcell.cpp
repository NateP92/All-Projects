// Program 2 - Nate Purcell.cpp | CS 201-R | T/R 11:30-12:45 | Program 2 Due date: 26 Sep 21

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

//Function Declarations
int GenerateCardNumber();
int PlayRound();

int main()
{
	//Var Declarations
	int player1steps = 0;
	int player2steps = 0;
	int roundCounter = 1;

	srand(time(NULL));

	//Greeting to user
	cout << "-----------------------------------" << endl;
	cout << "***Welcome to Sorry Board Game***" << endl;
	cout << "***Game will be played with 2 players***" << endl;
		

	//While loop to iterate each round and add any score gained to each score
	//while ((player1steps != 30) && (player2steps!= 30))
	//{
	//	cout << endl;															 FIX ME: Each iteration will be a round; for each round you will have to check the players score to make sure it isn't
	//																			   		   going over 30. If player1steps = 28 at the beginning of the round and they get 3 steps during their round, it
	//																					   must contine() and not add anything. While loop is gonna need a nested 'for' loop to play for each player
	//}

}

//Functions
//(1) GenerateCardNumber() will generate a random number between 1 and 12
//		- Takes an int and returns an int
//(2) A function to play a round would be helpful
//		- Returns the number of points the player gets
//		- Takes an integer from main which is the player1steps or player2steps var (maybe not -- it might only need to return a variable, not take one)
//		- Calls function to randomly generate a number
//		- Can use is/else ifs to decide how the score is added (else shouldn't be needed) Honestly could consider doing a switch
// 
//(3) I can keep track of the points in main so that way they don't ever get messed up and then always pass by value
//
int GenerateCardNumber()
{
	int cardNumber;
	cardNumber = (rand() % 12) + 1;
	return cardNumber;
}

int PlayRound(int currentScore, int playerNumber)
{
	int newSteps = 0;
	int cardNumber;
	cardNumber = GenerateCardNumber();
	if (currentScore == 0 && cardNumber > 3)
		{
		cout << "You got " << cardNumber << "! Did not get (1 or 2)" << endl;
		cout << "Need to skip your turn" << endl;
		cout << "Total steps for Player " << playerNumber << ": 0" << endl;
		return 0;
		}
	else if (cardNumber == 4)
		{
		cout << "Your card is 4" << endl;
		cout << "You can move to your opponents spot";                          //FIX ME: Did not finish the logic on these branches yet. Currently working through how the function will speak to main
																				//		  and make sure that if the player gets a 4 that they can actually change the other player's score -- will have
																				//        to pass by reference instead of pass by value. 
		}
	return newSteps;
}