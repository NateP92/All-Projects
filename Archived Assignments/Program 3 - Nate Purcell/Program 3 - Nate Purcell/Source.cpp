//Program 3 | Nate Purcell | Due: 17 Oct 21 | CS-201R
//Goal: 1. Read in office supplies from a text file
//      2. Use a menu system to allow the user to decide what to do w/ dat from .txt file
//      3. Calculate the total cost of supplies for either electronics or office items
//      4. Menu system will allow the user to output a single type of data to the screen or all data to a .txt file
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"
using namespace std;


void main()
{
	//Var Declaration																						
	vector<char> itemType;																							
	vector<int> numItems;
	vector<string> officeItem;
	vector<string> itemPrice;
	vector<double> newItemPrice;
	bool keepGoing = true;
	int menuChoice;

	//Welcome prompt
	cout << "Welcome to the Office Inventory System!" << endl;
	cout << "Please choose from the following options to begin." << endl;

	//Take all data from input file
	InputData(itemType, numItems, officeItem, itemPrice);

	//Data for itemPrice is input as a string. This function takes all of those strings, casts them to a double, and places them in a new vector
	ConvertStringVector(itemPrice, newItemPrice);

	//MainMenu() function call
	while (keepGoing)
	{
		menuChoice = MainMenu();
		switch (menuChoice)
		{
		case 1:
			cout << endl;
			OutputElectronics(itemType, numItems, officeItem, newItemPrice);
			break;
		case 2:
			cout << endl;
			OutputOfficeSupplies(itemType, numItems, officeItem, newItemPrice);
			break;
		case 3:
			cout << endl;
			OutputToTxt(itemType, numItems, officeItem, newItemPrice);
			cout << endl;
			cout << "A summary of your total costs has been sent to a file." << endl;
			cout << endl;
			break;
		case 4:
			cout << "Thank you for using the Office Inventory System. Have a good day!" << endl;
			keepGoing = false;
			return;
		default:
			cout << "Invalid input. Please select from the following options:" << endl;
			break;
		}
	}

	return;
}	
