#include <stdio.h>

int front = -1;
int rear = -1;
int size = 5;

int isEmpty()
{
	if (rear == front)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (rear == size - 1)
		return 1;
	else
		return 0;
}

void addQ(int q[], int elem)
{
	if (isFull())
		printf("\n*Queue is full!*\n");
	else{
		q[++rear] = elem;
	}
}

int delQ(int q[])
{
	if (isEmpty()){
		printf("\n*Queue is empty!*\n");
		return 0;
	}
	else{
		return q[++front];
	}
}

void display(int q[])
{
	printf("\nCurrent queue:\n\n");
	if (isEmpty())
		printf("*Nothing to display!*");
	else
		for (int i = front + 1; i <= rear; i++){
			printf("%d\t", q[i]);
		}
	printf("\n\n");
}

int main()
{
	int q[size];
	printf("\nSize of queue: %d\n", size);
	int choice = 0, elem;

	do {
		display(q);
		printf("\nSelect operation:\n1 - Add an element\n2 - Remove an element\n3 - Exit\n\nYour choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter element: ");
			scanf("%d", &elem);
			addQ(q, elem);
			break;
		case 2:
			if (!isEmpty())
				printf("\n*Element \" %d \" has been removed from queue.*\n", delQ(q));
			else
				delQ(q);
			break;
		case 3:
			printf("\nYou have chosen to exit the program.\nBye bye!\n\n");
			return 0;
		default:
			printf("*Invalid operation. Try again!*");
		}
	} while (choice != 3);
}
