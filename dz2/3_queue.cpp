#include<iostream>

using namespace std;

struct FIFO {
	int data;
	struct FIFO* next;
};

struct FIFO* front = NULL;
struct FIFO* rear = NULL;

void Enqueue(int x) {
	struct FIFO* temp = new FIFO;
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}


void Dequeue() {
	struct FIFO* temp = front;
	if (front == NULL)
	{
		cout << "Queue is empty!" << endl;
		return;
	}
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

void Print() {
	struct FIFO* temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int n = 1;
	while (n != 0)
	{
		cout << "add element to queue: ";
		cin >> n;
		Enqueue(n);
		cout << endl;
	}

	cout << "Queue element: ";
	Print();
	cout << "After deleting first element: ";
	Dequeue();
	Print();
}