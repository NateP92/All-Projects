//Assignment 2 for CS 303; Authored by Nate Purcell
//Due 6 Mar 2023
#include <iostream>
#include <string>
#include <fstream>
#include "SLL.h"
using namespace std;

ListNode::ListNode(int data) {
this->data = data;
this->next = NULL;
}

ListNode::ListNode(int data, ListNode* next) {
	this->data = data;
	this->next = next;
};

int ListNode::getData() { return data; };

ListNode* ListNode::getNext() { return next; };

void ListNode::setData(int data) {
	this->data = data;
};

void ListNode::push_front() {
	int newData;
	cout << "Please enter an integer: " << endl;
	cin >> newData;
	ListNode* newNode = new ListNode(newData, this->next);
	this->next = newNode;
};

void ListNode::push_back() {};

void ListNode::pop_front() {};

void ListNode::pop_back() {};

void ListNode::back() {};

void ListNode::front() {};

void ListNode::empty() {};

void ListNode::insert() {};

bool ListNode::remove(int index) { return true; };

void ListNode::find(int index) {};