#pragma once
#include <iostream>

using namespace std;

class Stack
{
private:
	int* data;
	int top;
	int size;
public:
	Stack(int size);
	void push(const int& object);
	void pushToPosition(const int& object, const int& position);
	int pop();
	int getSize() const;
	bool isEmpty();
	bool isFull();
	~Stack();
};
