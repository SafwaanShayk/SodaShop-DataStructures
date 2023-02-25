// Queue implementation
#include<iostream>
#include <string.h>
using namespace std;
#define MAX 100 //to define capacity of an array

int QUEUE[MAX], front = -1, rear = -1, customer_num = 000;

void enqueue(int QUEUE[], int customer_num) //add to queue
{
	if (rear == -1) //for enqueuing first element
	{
		front = rear = 0;
		QUEUE[rear] = customer_num;
	}
	else if (rear == MAX - 1) //if queue is full
	{
		cout << "\nWaiting List is full.\n";
		return;
	}
	else //if adding an element to a queue that already contains an element
	{
		rear++;
		QUEUE[rear] = customer_num;
	}

}

void generate_customer_num() //generate a number and add to queue
{
	customer_num = customer_num + 1;
	cout << "\n\nYou are customer number: " << customer_num;
	cout << "\n\n";
	enqueue(QUEUE, customer_num);
}

void view(int QUEUE[]) //to traverse or view the queue
{
	if (rear == -1) //the queue is empty
	{
		cout << "\nWaiting Line is Empty.";
		cout << "\n\n";
		return;
	}

	//if the queue contains an element
	cout << "\nWaiting Line:\n";
	for (int i = front;i <= rear;i++)
	{
		cout << "\n" << QUEUE[i];
	}
	cout << "\n";

}

void update(int QUEUE[]) //to remove topmost element
{
	//if the queue is empty
	if (front == -1)
	{
		cout << "\nWaiting Line is Empty.";
		cout << "\n\n";
		return;
	}
	else if (front == rear) //if removing the topmost element before the queue gets empty
	{
		customer_num = QUEUE[front];
		front = rear = -1;
	}
	else //to remove the topmost element and adjust the queue
	{
		customer_num = QUEUE[front];
		front++;
	}
	cout << "\nNow Serving Customer Number: " << customer_num;
	cout << "\n\n";
}

void Soda() {
	int choice;
	cout << "Which Soda You Want to Buy: \n";
	cout << "\n 1) " << "Coka Cola" << "\t\t" << 0.75;
	cout << "\n 2) " << "Root Beer" << "\t\t" << 0.75;
	cout << "\n 3) " << "Lemon Lime" << "\t\t" << 0.75;
	cout << "\n 4) " << "Grape Soda" << "\t\t" << 0.80;
	cout << "\n 5) " << "Cream Soda" << "\t\t" << 0.80;
	cout << "\n\nEnter Choice: ";
	cin >> choice;

	if (choice == 1) {
		cout << "Customer(" << customer_num << ") Soda is : Coka Cola\n";

	}
	else if (choice == 2) {
		cout << "Customer(" << customer_num << ") Soda is : Root Bear\n";

	}
	else if (choice == 3) {
		cout << "Customer(" << customer_num << ") Soda is : Lemon Lime\n";

	}
	else if (choice == 4) {
		cout << "Customer(" << customer_num << ") Soda is : Grape Soda\n";

	}
	else if (choice == 5) {
		cout << "Customer(" << customer_num << ") Soda is : Cream Soda\n";

	}
	else {
		cout << "\n\nInvalid Choice";
	}
}

int main()
{
	/*	the 'customer' is just to generate a number that will be enqueued
		the 'admin' is for the user to view and remove elements from the queue */
	cout << "\t\t----------------------------------\n";
	cout << "\t\t-----Welcome to the Soda Shop-----\n";
	cout << "\t\t----------------------------------\n\n";

start:
	int choice_admin, choice_customer, start;


	cout << "\nAre you a Customer (1) or an Admin (0)? : ";
	cin >> start;

	//customer
	if (start == 1)
	{
		cout << "\n***Good day, Customer!**";

		//genreate a number and automatically adds it to the queue
		generate_customer_num();
		Soda();
		cout << "\n\n";

		goto start;
	}

	//admin account
	else if (start == 0)
	{
		cout << "\n***Good day, Admin!**\n";
		while (1)
		{
			cout << "\n1.View Waiting Line\n2.Update 'Now Serving' number\n3.Quit\n\n";
			cout << "What would you like to do? : ";
			cin >> choice_admin;

			switch (choice_admin)
			{
			case 1:
			{
				//view the elements on the queue
				view(QUEUE);
				break;
			}
			case 2:
			{
				//remove the topmost element on the queue
				update(QUEUE);
				view(QUEUE);
				break;
			}
			case 3:
			{
				//to exit the 'admin' account
				cout << "\n";
				goto start;
			}
			default:
			{
				cout << "Invalid input.";
				cout << "\n\n";
			}
			}
		}
	}
	else
	{
		cout << "Invalid input. Plese Try again.";
		cout << "\n\n";
		goto start;
	}
}