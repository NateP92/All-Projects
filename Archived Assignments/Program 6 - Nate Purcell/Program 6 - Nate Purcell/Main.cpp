//Program 6 | Nate Purcell | CS 201-R | Due: 11 Dec 21
#include <iostream>
#include <string>
#include "PatientQueue.h"
using namespace std;

Patient* HeartClinic = NULL;
Patient* LungClinic = NULL;
Patient* PlasticSurgery = NULL;
int heartClinicCtr = 0;
int lungClinicCtr = 0;
int plasticSurgeryCtr = 0;


int main() {
	int menuItem = MainMenu();		//Main Menu will be opened, then a clinic is chosen until
	while (menuItem != 4)			//the user decides to exit
	{
		cout << endl;
		switch (menuItem)
		{
		case 1:
			HeartClinic = ClinicMenu("Heart Clinic", HeartClinic, heartClinicCtr);
			break;
		case 2:
			LungClinic = ClinicMenu("Lung Clinic", LungClinic, lungClinicCtr);
			break;
		case 3:
			PlasticSurgery = ClinicMenu("Plastic Surgery", PlasticSurgery, plasticSurgeryCtr);
			break;
		case 4:
			cout << "Exiting program..";
			return 0;
		}
		menuItem = MainMenu();
	}
	return 0;
}