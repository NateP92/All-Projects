//Program 6 | Nate Purcell | CS 201-R | Due: 11 Dec 21
#pragma once
#ifndef PATIENTQUEUE_H
#define PATIENTQUEUE_H
#include <iostream>
#include <string>
using namespace std;

struct Patient {
	string firstName;
	string lastName;
	int SSN;
	Patient* next;
};

Patient* AddPatient(Patient* head, int& ctr);

Patient* AddCriticallyIll(Patient* head, int& ctr);

Patient* PopPatient(Patient* head, int& ctr);

Patient* CancelPatient(Patient* head, int& ctr);

void ListPatients(Patient* head);

int MainMenu();

Patient* ClinicMenu(string clinic, Patient* head, int& ctr);

#endif
