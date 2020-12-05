#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

struct stack
{
	int *arr;
	int top;
	int capacity;
	stack(int size = SIZE);

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};

stack::stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

void stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	arr[++top] = x;
}

int stack::pop()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	cout << peek() << endl;
	return arr[top--];
}

int stack::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

int stack::size()
{
	return top + 1;
}

bool stack::isEmpty()
{
	return top == -1;
}

bool stack::isFull()
{
	return top == capacity - 1;
}

int main()
{
	int n;
	cin >> n;
	stack pt(n);
	int h;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		pt.push(h);
	}
	for (int i = 0; i < n; i++)
	{
		pt.peek();
		pt.pop();
	}

	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}