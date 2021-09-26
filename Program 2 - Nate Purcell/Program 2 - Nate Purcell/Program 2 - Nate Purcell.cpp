// Program 2 - Nate Purcell.cpp | CS 201-R | T/R 11:30-12:45 | Program 2 Due date: 26 Sep 21

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

//Function Declarations
int GenerateCardNumber();
void PlayRound(int& currentSteps, int& opponentSteps, int playerNumber, bool& onStart);

int main()
{
	//Var Declarations
	int player1steps = 0;
	int player2steps = 0;
	int roundCounter = 1;
	bool player1onStart = true;
	bool player2onStart = true;
	char keepPlaying = 'y';

	srand(time(NULL));

	//Greeting to user
	cout << "--------------------------------------------------" << endl;
	cout << "***Welcome to Sorry Board Game***" << endl;
	cout << "***Game will be played with 2 players***" << endl;
	cout << "--------------------------------------------------" << endl;

	//Outer loop ensures the user can keep playing if they choose -- inner loop will continuously play rounds until a player has won
	while (keepPlaying == 'y' || keepPlaying == 'Y')
	{
		while (player1steps != 30 || player2steps != 30)
		{
			cout << "-------------------------------------------" << endl;
			cout << "****Round " << roundCounter << "****" << endl;
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cout << "***Player 1***" << endl;
			cout << "-------------------------------------------" << endl;
			PlayRound(player1steps, player2steps, 1, player1onStart);
			cout << "-------------------------------------------" << endl;
			cout << "***Player 2***" << endl;
			cout << "-------------------------------------------" << endl;
			PlayRound(player2steps, player1steps, 2, player2onStart);
			roundCounter++;
			cout << endl;
			cout << endl;

			if (player1steps == 30)
			{
				cout << "Player 1 is the winner" << endl;
				cout << "Good game!" << endl;
				break;
			}
			if (player2steps == 30)
			{
				cout << "Player 2 is the winner" << endl;
				cout << "Good game!" << endl;
				break;
			}
		}
	//Prompt user to play again
	cout << "Do you want to have another turn? (Y/y for yes, N/n for No)" << endl;
	cin >> keepPlaying;
	if (keepPlaying == 'n' || keepPlaying == 'N')
		{
			cout << "Thank you for playing the Sorry Board Game!" << endl;
			return 0;
		}
		
	}
		
	return 0;
}

//Functions
//(1) GenerateCardNumber() will generate a random number between 1 and 12
//		- Takes an int and returns an int
//(2) A function to play a round would be helpful
//		- Changes the number of points the player gets
//		- Knows which player is playing from playerNumber var
//		- Calls function to generate a card number
//		- Uses nested if/else statements to determime how to proceed if the player is on start or off start
//		- Exits automatically when a player goes over 30 steps, increases their steps, or fails to make it off start

int GenerateCardNumber()
{
	int cardNumber;
	cardNumber = (rand() % 12) + 1;
	return cardNumber;
}

void PlayRound(int& currentSteps, int& opponentSteps, int playerNumber, bool& onStart)
{
	int newSteps = 0;
	int cardNumber;
	int playerChoice = 0;
	int tempSteps;
	
	//Generate random number betweeen 1 & 12 for cardNumber var
	cardNumber = GenerateCardNumber();

	//Check to see if player is on start position, rolls a 4, or just needs to add steps to their score
	if (onStart == true && cardNumber >= 3)
	{
		cout << "You got " << cardNumber << "! Did not get (1 or 2)" << endl;
		cout << "Need to skip your turn" << endl;
		cout << "Total steps for Player " << playerNumber << ": 0" << endl;
		return;
	}
	else if (onStart == true && cardNumber < 3)
	{
		if (cardNumber == 1)
		{
			currentSteps = 0;
			onStart = false;
			cout << "Your card is " << cardNumber << endl;
			cout << "You can now move off of start on your next turn." << endl;
			cout << "Total steps for Player " << playerNumber << ": " << currentSteps << endl;
			return;
		}
		else
		{
			currentSteps = 1;
			onStart = false;
			cout << "You Are Lucky , You Got " << cardNumber << endl;
			cout << "Total steps for Player " << playerNumber << ": " << currentSteps << endl;
			return;
		}

	}
	else if (cardNumber == 4 && onStart != true) //For when the player draws a 4
	{
		cout << "Your card is 4" << endl;
		cout << "You can move to your opponent's spot, or move 4 steps" << endl;                          
		cout << "What is your choice (1: move 4 steps, 2: take opponent spot)" << endl;
		cin >> playerChoice;

		//Just in case the user doesn't input 1 or 2									
		while (playerChoice != 1 && playerChoice != 2)
		{
			cout << "Incorrect input, please choose '1' or '2'" << endl;
			cin >> playerChoice;
		}

		//Adding steps or swapping steps
		if (playerChoice == 1)
		{
			currentSteps += cardNumber;
			cout << "You can move 4 more steps!" << endl;
			cout << "Total steps for Player " << playerNumber << ": " << currentSteps << endl;
		}
		else 
		{
			tempSteps = opponentSteps;
			opponentSteps = currentSteps;
			currentSteps = tempSteps;
			cout << "Total steps for Player " << playerNumber << ": " << currentSteps << endl;
		}
		return;
	}
	else 
	{
		cout << "Your card is " << cardNumber << endl;
		cout << "You can move: " << cardNumber << " steps!" << endl;

		//Catching those cases when currentSteps + cardNumber > 30
		if ((cardNumber + currentSteps) > 30)
		{
			cout << "Oops! You need exactly 30 points to win! Try again!" << endl;
			cout << "Total steps for Player " << playerNumber << ": " << currentSteps << endl;
			return;
		}

		//Or just add their steps and finish the round
		currentSteps += cardNumber;
		cout << "Total steps for " << playerNumber << ": " << currentSteps << endl;
		return;
	}


	return;
}