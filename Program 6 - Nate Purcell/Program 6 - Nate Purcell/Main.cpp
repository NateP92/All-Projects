//Program 6 | Nate Purcell | CS 201-R | Due: 11 Dec 21
#include <iostream>
#include <string>
#include "PatientQueue.h"
using namespace std;

struct Patient {
	string firstName;
	string lastName;
	int SSN;
	Patient* next;
};

int main() {
	Patient* head;
	head = new Patient();
	head->next = NULL;
	head->firstName = "Sally";
	head->lastName = "Thompson";
	head->SSN = 123456789;

	Patient* p1 = new Patient();
	head->next = p1;
	p1->firstName = "Naddy";
	p1->lastName = "Darnell";
	p1->next = NULL;

	cout << "first name of node after head is : " << head->next->firstName << endl;
	//cout << "first name is : " << head->firstName << endl;
	//cout << "last name is : " << head->lastName << endl;
	//cout << "SSN is : " << head->SSN << endl;


	return 0;
}