#include <stdio.h>
#include <ctype.h>

#define MAX 20

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

int icp(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 4;
	case '(':
		return 5;
	default:
		return 0;
	}
}

int isp(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

void in_post(char inexp[], char post[])
{
	int k = 0, i = 0;
	char tkn = inexp[i];

	while (tkn != '\0') {
		if (isalpha(tkn))
			post[k++] = inexp[i];
		else if (tkn == '(')
			push('(');
		else if (tkn == ')')
			while ((tkn = pop()) != '(')
				post[k++] = tkn;
		else {
			while (!isEmpty() && isp(stk[top]) >= icp(tkn))
				post[k++] = pop();
			push(tkn);
		}

		tkn = inexp[++i];
	}

	while (!isEmpty()) {
		post[k++] = pop();
	}
}

int main()
{
	char inexp[50], post[50];
	printf("\n\nEnter infix expression: ");
	scanf("%s", inexp);
	in_post(inexp, post);
	printf("\nPostfix expression: %s\n\n", post);

	return 0;
}
