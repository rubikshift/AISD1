#include "stack.h"

Stack::Stack()
{
	this->top = 0;
}

void Stack::push(const int& object)
{
	this->data[this->top] = object;
	this->top++;
}

void Stack::pushToPosition(const int & object, const int & position)
{
	this->data[position] = object;
	if (this->top < position + 1)
		this->top = position + 1;
}

int Stack::pop()
{
	int temp = this->data[this->top - 1];
	this->top--;
	return temp;
}

int Stack::getSize() const
{
	return this->top;
}

bool Stack::isEmpty()
{
	return top == 0;
}

bool Stack::isFull()
{
	return top == NUMBER_OF_CARS;
}

Stack::~Stack()
{
	this->top = 0;
}
