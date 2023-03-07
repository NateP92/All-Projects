//Assignment 2 for CS 303; Authored by Nate Purcell
//Due 6 Mar 2023
#include <iostream>
#include <string>
#include <fstream>
#include "SLL.h"
using namespace std;

int main()
{
	ListNode* head = new ListNode();
	ListNode* first = new ListNode(head->getData() - 1, NULL);
	ListNode* toPush = new ListNode(8, NULL);
	head->next = first;
	cout << head->getData() << endl << head->next->getData();

	
	return 0;
}  