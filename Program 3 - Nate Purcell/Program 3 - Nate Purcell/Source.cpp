//Program 3 | Nate Purcell | Due: 17 Oct 21 | CS-201R
//Goal: 1. Read in office supplies from a text file
//      2. Use a menu system to allow the user to decide what to do w/ dat from .txt file
//      3. Calculate the total cost of supplies for either electronics or office items
//      4. Menu system will allow the user to output a single type of data to the screen or all data to a .txt file

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int MainMenu()
{
	//Inventory Menu
	int menuChoice;

	cout << "              ***** Option Menu *****" << endl;
	cout << "Press (1) for the total cost of all electronic products." << endl;
	cout << "Press (2) for the total cost of all office supply products." << endl;
	cout << "Press (3) for to generate a summary report for the total cost of all products." << endl;
	cout << "Press (4) to exit." << endl;
	cin >> menuChoice;

	return menuChoice;
}

void InputData(vector<char> &itemType, vector<int> &numItems, vector<string> &officeItem, vector<string> &itemPrice)
{
	char tempChar;
	int tempInt;
	string tempString;
	string tempPrice;
	ifstream fin;
	fin.open("Office.txt");
	

	while (fin.good())
	{
		fin.clear();
		fin >> tempChar;
		fin >> tempInt;
		fin >> tempString;
		fin >> tempPrice;

		itemType.push_back(tempChar);
		numItems.push_back(tempInt);
		officeItem.push_back(tempString);
		itemPrice.push_back(tempPrice);
		
	}
	fin.close();

	itemType.pop_back();
	numItems.pop_back();
	officeItem.pop_back();
	itemPrice.pop_back();

	return;
}

void ConvertStringVector(vector<string> vectorString, vector<double> &newItemPrice)
{
	double newDouble;
	for (int i = 0; i < vectorString.size(); i++)
	{
		vectorString.at(i).erase(0, 1); //Erases the '$' sign
		newDouble = stod(vectorString.at(i)); //Casts the string to type double
		newItemPrice.push_back(newDouble); //Takes the new double and pushes it back into a new vector;
	}
	return;
}

void OutputElectronics(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice)
{
	double totalElectronicCost = 0;
	double totalItemCost;
	for (int i = 0; i < itemType.size(); i++)
	{
		if (itemType.at(i) == 'E')
		{
			cout << setw(1) << left << itemType.at(i);
			cout << setw(20) << right << officeItem.at(i) << "          ";
			cout << setw(10) << right << "Quantity: " << numItems.at(i) << "          ";
			cout << setw(20) << left << "price/piece:  " << newItemPrice.at(i);
			totalItemCost = newItemPrice.at(i) * numItems.at(i);
			totalElectronicCost += totalItemCost;
			cout << setw(20) << right << "Total: $" << totalItemCost;
			cout << endl;
		}
	}
	cout << "--------------------------------------------------------" << endl;
	cout << "Total Price for Electronics in Inventory: $ " << totalElectronicCost << endl;
	cout << "--------------------------------------------------------" << endl;
	return;
}

void OutputOfficeSupplies(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice)
{
	double totalOfficeCost = 0;
	double totalItemCost;
	for (int i = 0; i < itemType.size(); i++)
	{
		if (itemType.at(i) == 'O')
		{
			cout << setw(1) << left << itemType.at(i);
			cout << setw(20) << right << officeItem.at(i) << "          ";
			cout << setw(10) << left << "Quantity: " << numItems.at(i) << "          ";
			cout << setw(20) << left << "price/piece:  " << newItemPrice.at(i);
			totalItemCost = newItemPrice.at(i) * numItems.at(i);
			totalOfficeCost += totalItemCost;
			cout << setw(20) << right << "Total: $" << totalItemCost;
			cout << endl;
		}
	}
	cout << "--------------------------------------------------------" << endl;
	cout << "Total Price for Office Supplies in Inventory: $ " << totalOfficeCost << endl;
	cout << "--------------------------------------------------------" << endl;
	return;
}

void OutputToTxt(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice)
{
	ofstream fout;
	fout.open("Summary.txt");

	double totalCost = 0;
	double totalItemCost;

	for (int i = 0; i < itemType.size(); i++)
	{
		if (itemType.at(i) == 'E')
		{
			fout << setw(1) << left << itemType.at(i);
			fout << setw(20) << right << officeItem.at(i) << "          ";
			fout << setw(10) << left << "Quantity: " << numItems.at(i) << "          ";
			fout << setw(20) << left << "price/piece:  " << newItemPrice.at(i);
			totalItemCost = newItemPrice.at(i) * numItems.at(i);
			totalCost += totalItemCost;
			fout << setw(20) << right << "Total: $" << totalItemCost;
			fout << endl;
		}
	}
	fout << "--------------------------------------------------------" << endl;
	fout << "Total Price for Electronics in Inventory: $ " << totalCost << endl;
	fout << "--------------------------------------------------------" << endl;

	totalCost = 0;
	totalItemCost = 0;
	for (int i = 0; i < itemType.size(); i++)
	{
		if (itemType.at(i) == 'O')
		{
			fout << setw(1) << left << itemType.at(i);
			fout << setw(20) << right << officeItem.at(i) << "          ";
			fout << setw(10) << left << "Quantity: " << numItems.at(i) << "          ";
			fout << setw(20) << left << "price/piece:  " << newItemPrice.at(i);
			totalItemCost = newItemPrice.at(i) * numItems.at(i);
			totalCost += totalItemCost;
			fout << setw(20) << right << "Total: $" << totalItemCost;
			fout << endl;
		}
	}
	fout << "--------------------------------------------------------" << endl;
	fout << "Total Price for Office Supplies in Inventory: $ " << totalCost << endl;
	fout << "--------------------------------------------------------" << endl;

	fout.close();
	return;
}

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
