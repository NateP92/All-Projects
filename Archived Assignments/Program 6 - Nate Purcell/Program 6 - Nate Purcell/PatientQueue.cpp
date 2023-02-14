//Program 6 | Nate Purcell | CS 201-R | Due: 11 Dec 21
#include <iostream>
#include <string>
#include "PatientQueue.h"
using namespace std;

Patient* AddPatient(Patient* head, int& ctr) {
	if (ctr > 100)
	{
		cout << "There are 100 or more patients in queue. Please wait for patients to be removed before adding more." << endl;
		return head;
	}
	string first, last;
	int social;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << endl << "Enter patient's last name: ";
	cin >> last;
	cout << endl << "Enter patient's SSN: ";
	cin >> social;

	//Confirm patient info
	cout << "Patient Information Review - please review all information for correctness" << endl;
	cout << "First Name: " << first << endl;
	cout << "Last Name: " << last << endl;
	cout << "SSN: " << social << endl;

	Patient* toAdd = new Patient();
	toAdd->firstName = first;
	toAdd->lastName = last;
	toAdd->SSN = social;
	toAdd->next = NULL;

	if (head == NULL)
	{
		head = toAdd;
		ctr++;
		return head;
	}
	else 
	{
		Patient* temp;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = toAdd;
	}
	ctr++;
	return head;
}

Patient* AddCriticallyIll(Patient* head, int& ctr) 
{
	string first, last;
	int social;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << endl << "Enter patient's last name: ";
	cin >> last;
	cout << endl << "Enter patient's SSN: ";
	cin >> social;

	Patient* toAdd = new Patient();
	toAdd->firstName = first;
	toAdd->lastName = last;
	toAdd->SSN = social;
	
	toAdd->next = head; //New patient points to the current 1st, in line
	head = toAdd;			  //Head now points to the new patient
	ctr++;					  //Update number of patients in queue
	return head;
}

Patient* PopPatient(Patient* head, int& ctr) {
	if (head == NULL)
	{
		cout << "No patients in queue." << endl;
		return head;
	}
	head = head->next;
	ctr--;
	return head;
}

Patient* CancelPatient(Patient* head, int& ctr) { 
	string first, last;
	int social;
	cout << endl << "-- Patient Cancellation Menu --" << endl;
	cout << "Enter patient's first name: ";
	cin >> first;
	cout << endl << "Enter patient's last name: ";
	cin >> last;
	cout << endl << "Enter patient's SSN: ";
	cin >> social;

	Patient* temp;
	temp = head;

	if ((temp->firstName == first) && (temp->lastName == last) && (temp->SSN == social))
	{
		cout << "**REMOVING FIRST ITEM IN LIST**" << endl;
		head = head->next;
		ctr--;
		return head;
	}
	else {
		cout << "**SEARCHING FOR NEW ITEM**" << endl;
		while (temp->next != NULL)
		{
			if ((temp->next->firstName == first) && (temp->next->lastName == last) && (temp->next->SSN == social))
			{
				temp->next = temp->next->next;
				ctr--;
				return head;
			}
			temp = temp->next;
		}
	}
}

void ListPatients(Patient* head) {
	int counter = 1;
	if (head == NULL)
	{
		cout << "Queue for this clinic is empty" << endl;
		return;
	}
	else {
		Patient* temp;
		temp = head;
		cout << endl << "Patient(s) in queue: " << endl;
		while (temp != NULL)
		{
			cout << "Patient " << counter << ": ";
			cout << temp->firstName << " " << temp->lastName << ", " << temp->SSN << endl;
			counter++;
			temp = temp->next;
		}
	}
}

int MainMenu() {
	cout << "Welcome to 201 Hospital" << endl;
	cout << "1: Heart Clinic" << endl;
	cout << "2: Lung Clinic" << endl;
	cout << "3: Plastic Surgery" << endl;
	cout << "4: Exit" << endl;
	cout << "Please enter your choice:" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		//Hearth Clinic
		return 1;
	case 2:
		//Lung Clinic
		return 2;
	case 3:
		//Plastic Surgery
		return 3;
	case 4:
		//Exit
		return 4;
	default:
		//Invalid entry backup
		cout << "Invalid input. Please select from the following options: " << endl;
		cout << "1: Heart Clinic" << endl;
		cout << "2: Lung Clinic" << endl;
		cout << "3: Plastic Surgery" << endl;
		cout << "4: Exit" << endl;
		cout << "Please enter your choice:" << endl;
		cin >> choice;
	}
}

Patient* ClinicMenu(string clinic, Patient* head, int& ctr) {
	cout << "Welcome to department : " << clinic << endl;
	cout << "Please enter your choice : " << endl;
	cout << "1: Add Patient" << endl;
	cout << "2: Add critically ill patient" << endl;
	cout << "3: Take out patient for operation" << endl;
	cout << "4: Cancel patient" << endl;
	cout << "5: List the queue of patients" << endl;
	cout << "6: Change department or exit" << endl;
	int menuChoice;
	cin >> menuChoice;
	switch (menuChoice)
	{
	case 1:
		head = AddPatient(head, ctr);
		return head;
	case 2:
		head = AddCriticallyIll(head, ctr);
		return head;
	case 3:
		head = PopPatient(head, ctr);
		return head;
	case 4:
		head = CancelPatient(head, ctr);
		return head;
	case 5:
		ListPatients(head);
		return head;
	case 6:
		return head;
	defaut:
		//Invalid entry backup
		cout << "Invalid input. Please select from the following options: " << endl;
		cout << "1: Add Patient" << endl;
		cout << "2: Add critically ill patient" << endl;
		cout << "3: Take out patient for operation" << endl;
		cout << "4: Cancel patient" << endl;
		cout << "5: List the queue of patients" << endl;
		cout << "6: Change department or exit" << endl;
		cout << "Please enter your choice:" << endl;
		cin >> menuChoice;
	}
}
