//Program 3 | Nate Purcell | Due: 17 Oct 21 | CS-201R
//Goal: 1. Read in office supplies from a text file
//      2. Use a menu system to allow the user to decide what to do w/ dat from .txt file
//      3. Calculate the total cost of supplies for either electronics or office items
//      4. Menu system will allow the user to output a single type of data to the screen or all data to a .txt file

#include <fstream>
#include <iostream>
using namespace std;

void main()
{
	//Var Declaration																						FIX ME: I need to decide how I want to save the data from the input file
	char itemType;																							//I'll likely either need to create a structure, a class, or a series of vectors
	int numItems;
	string officeItem;
	double itemPrice;
	bool keepGoing = true;

	//File Stream Objects
	ifstream fin;
	ofstream fout;

	//Welcome prompt
	cout << "Welcome to the Office Inventory System!" << endl;
	cout << "Please choose from the following options to begin." << endl;

	//Inventory Menu
	int menuChoice;
	while (keepGoing)
	{
		cout << "              ***** Option Menu *****" << endl;
		cout << "Press (1) for the total cost of all electronic products." << endl;
		cout << "Press (2) for the total cost of all office supply products." << endl;
		cout << "Press (3) for to generate a summary report for the total cost of all products." << endl;
		cout << "Press (4) to exit." << endl;

		cin >> menuChoice;

		switch (menuChoice)
		{
			case 1:																							//FIX ME: Once i decide how to implement each case I'll have to add the logic here
				cout << "Option 1 chosen. Still need to add functionality." << endl;						//Each case should call the relative function needed
				break;
			case 2:
				cout << "Option 2 chosen. Still need to add functionality." << endl;
				break;
			case 3:
				cout << "Option 3 chosen. Still need to add functionality." << endl;
				break;
			case 4:
				cout << "Thank you for using the Office Inventory System. Have a good day!" << endl;
				return;
			default:
				cout << "Invalid input. Please select from the following options:" << endl;
				break;
		}
	}
	return;
}