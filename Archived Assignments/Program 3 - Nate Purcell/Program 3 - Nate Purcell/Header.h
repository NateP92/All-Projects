#pragma once
#ifndef SOURCE_H
#define SOURCE_H
using namespace std;

int MainMenu();

void InputData(vector<char>& itemType, vector<int>& numItems, vector<string>& officeItem, vector<string>& itemPrice);

void ConvertStringVector(vector<string> vectorString, vector<double>& newItemPrice);

void OutputElectronics(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice);

void OutputOfficeSupplies(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice);

void OutputToTxt(vector<char> itemType, vector<int> numItems, vector<string> officeItem, vector<double> newItemPrice);

#endif