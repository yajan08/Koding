#include <stdio.h>

#define MAX 5

char stk[MAX];
int top = -1;

int isFull()
{
	return top == MAX - 1;
}

int isEmpty()
{
	return top == -1;
}

void push(char item)
{
	if (!isFull())
		stk[++top] = item;
	else
		printf("\n*Stack is full!*\n");
}

char pop()
{
	if (!isEmpty())
		return stk[top--];

	printf("\n*Stack is empty!*\n");
	return '\0';
}

void display()
{
	printf("\nCurrent stack:\n\n");

	if (isEmpty())
		printf("*Empty*");
	else
		for (int i = top; i >= 0; i--)
			printf("%c\n", stk[i]);

	printf("\n");
}

int main()
{
	int choice = 0;
	char temp;
	printf("Stack size = %d\n", MAX);

	do {
		display();
		printf("\nWhat would you like to do?\n1 - Push an element\n2 - Pop an element\n3 - Exit\n\nYour choice: ");
		scanf(" %d", &choice);

		switch (choice) {
		case 1:
			printf("\nEnter element: ");
			scanf(" %c", &temp);
			push(temp);
			break;
		case 2:
			temp = pop();
			if (temp != '\0')
				printf("\nElement \" %c \" has been popped out of the stack.\n", temp);
			break;
		case 3:
			printf("\nYou have chosen to exit.\nBye bye!\n\n");
			return 0;
		default:
			printf("\nInvalid choice! Try again.\n");
		}

	} while (choice != 3);
}
