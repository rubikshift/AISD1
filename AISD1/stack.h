#pragma once
#include <iostream>

#define NUMBER_OF_CARS 10

using namespace std;

class Stack
{
private:
	int data[NUMBER_OF_CARS];
	int top;
public:
	Stack();
	void push(const int& object);
	void pushToPosition(const int& object, const int& position);
	int pop();
	int getSize() const;
	bool isEmpty();
	bool isFull();
	~Stack();
};
