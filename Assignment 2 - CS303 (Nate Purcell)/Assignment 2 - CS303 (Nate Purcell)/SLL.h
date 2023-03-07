//Assignment 2 for CS 303; Authored by Nate Purcell
//Due 6 Mar 2023
#pragma once
#ifndef SLL_H
#define SLL_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ListNode {
private:
	int data;
public:
	ListNode* next;
	ListNode(int data);
	ListNode(int data, ListNode* next);
	int getData();
	ListNode* getNext();
	void setData(int data);
	void push_front();
	void push_back();
	void pop_front();
	void pop_back();
	void back();
	void front();
	void empty();
	void insert();
	bool remove(int index);
	void find(int index);
};

#endif
