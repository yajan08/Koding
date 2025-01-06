#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 25

char stk[MAX][MAX];
int top = -1;

int isFull()
{
	return top == MAX - 1;
}

int isEmpty()
{
	return top == -1;
}

void push(char item[])
{
	if (!isFull())
		strcpy(stk[++top], item);
	else
		printf("\n*Stack is full!*\n");
}

void pop(char item[])
{
	if (!isEmpty())
		strcpy(item, stk[top--]);
	else
		printf("\n*Stack is empty!*\n");
}

void post_in(char postexp[], char inexp[])
{
	char op1[25], op2[25], x[25];

	for (int i = 0; postexp[i] != '\0'; i++) {
		x[0] = postexp[i];
		x[1] = '\0';

		if (isalpha(postexp[i]))
			push(x);
		else {
			pop(op2);
			pop(op1);

			strcpy(inexp, "(");
			strcat(inexp, op1);
			strcat(inexp, x);
			strcat(inexp, op2);
			strcat(inexp, ")");
			push(inexp);
		}
	}
}

void post_pre(char postexp[], char preexp[])
{
	char op1[50], op2[50], x[50];

	for (int i = 0; postexp[i] != '\0'; i++) {
		x[0] = postexp[i];
		x[1] = '\0';

		if (isalpha(postexp[i]))
			push(x);
		else {
			pop(op2);
			pop(op1);

			strcpy(preexp, x);
			strcat(preexp, op1);
			strcat(preexp, op2);
			push(preexp);
		}
	}
}

void strrev(char *str)
{
	int i;
	int j;
	char a;
	int len = strlen((const char *)str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}

void pre_in(char preexp[], char inexp[])
{
	char op1[25], op2[25], x[25];
	strrev(preexp);

	for (int i = 0; preexp[i] != '\0'; i++) {
		x[0] = preexp[i];
		x[1] = '\0';

		if (isalpha(preexp[i]))
			push(x);
		else {
			pop(op1);
			pop(op2);

			strcpy(inexp, "(");
			strcat(inexp, op1);
			strcat(inexp, x);
			strcat(inexp, op2);
			strcat(inexp, ")");
			push(inexp);
		}
	}
}

void pre_post(char preexp[], char postexp[])
{
	char op1[25], op2[25], x[25];
	strrev(preexp);

	for (int i = 0; preexp[i] != '\0'; i++) {
		x[0] = preexp[i];
		x[1] = '\0';

		if (isalpha(preexp[i]))
			push(x);
		else {
			pop(op1);
			pop(op2);

			strcpy(postexp, op1);
			strcat(postexp, op2);
			strcat(postexp, x);
			push(postexp);
		}
	}
}

char stk1[MAX];
int top1 = -1;

int isFull1()
{
	return top1 == MAX - 1;
}

int isEmpty1()
{
	return top1 == -1;
}

void push1(char item)
{
	if (!isFull1())
		stk1[++top] = item;
	else
		printf("\n*Stack is full!*\n");
}

char pop1()
{
	if (!isEmpty1())
		return stk1[top1--];
	else {
		printf("\n*Stack is empty!*\n");
		return '\0';
	}
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

void in_post(char inexp[], char postexp[])
{
	int k = 0, i = 0;
	char tkn = inexp[i];

	while (tkn != '\0') {
		if (isalpha(tkn))
			postexp[k++] = inexp[i];
		else if (tkn == '(')
			push1('(');
		else if (tkn == ')')
			while ((tkn = pop1()) != '(')
				postexp[k++] = tkn;
		else {
			while (!isEmpty1() && isp(stk1[top1]) >= icp(tkn))
				postexp[k++] = pop1();
			push1(tkn);
		}

		tkn = inexp[++i];
	}

	while (!isEmpty1()) {
		postexp[k++] = pop1();
	}
}

int icp1(char ch)
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
	case '(':
		return 5;
	default:
		return 0;
	}
}

int isp1(char ch)
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
	default:
		return 0;
	}
}

void in_pre(char inexp[], char preexp[])
{
	int k = 0, i = 0;
	char tkn = inexp[i];

	strrev(inexp);

	while (tkn != '\0') {
		if (isalpha(tkn))
			preexp[k++] = inexp[i];
		else if (tkn == ')')
			push1(')');
		else if (tkn == '(')
			while ((tkn = pop1()) != ')')
				preexp[k++] = tkn;
		else {
			while (!isEmpty1() && isp1(stk1[top1]) > icp1(tkn))
				preexp[k++] = pop1();
			push1(tkn);
		}

		tkn = inexp[++i];
	}

	while (!isEmpty1()) {
		preexp[k++] = pop1();
	}
	strrev(preexp);
}

int main()
{
	char inexp[50], postexp[50], preexp[50];
	int choice1, choice2;

	do {
		printf("\n\nChoose input expression type:\n1 - Infix\n2 - Prefix\n3 - Postfix\n4 - Exit\n\nYour choice: ");
		scanf("%d", &choice1);
		switch (choice1) {
		case 1:
			printf("\nEnter infix expression: ");
			scanf("%s", inexp);
			printf("\nChoose output expression type:\n1 - Prefix\n2 - Postfix\n\nYour choice: ");
			scanf("%d", &choice2);
			switch (choice2) {
			case 1:
				in_pre(inexp, preexp);
				printf("\nPrefix expression: %s\n", preexp);
				break;
			case 2:
				in_post(inexp, postexp);
				printf("\nPostfix expression: %s\n", postexp);
				break;
			default:
				printf("\nInvalid choice. Try again!\n");
			}
			break;
		case 2:
			printf("\nEnter prefix expression: ");
			scanf("%s", preexp);
			printf("\nChoose output expression type:\n1 - Infix\n2 - Postfix\n\nYour choice: ");
			scanf("%d", &choice2);
			switch (choice2) {
			case 1:
				pre_in(preexp, inexp);
				printf("\nInfix expression: %s\n", inexp);
				break;
			case 2:
				pre_post(preexp, postexp);
				printf("\nPostfix expression: %s\n", postexp);
				break;
			default:
				printf("\nInvalid choice. Try again!\n");
			}
			break;
		case 3:
			printf("\nEnter postfix expression: ");
			scanf("%s", preexp);
			printf("\nChoose output expression type:\n1 - Infix\n2 - Prefix\n\nYour choice: ");
			scanf("%d", &choice2);
			switch (choice2) {
			case 1:
				post_in(postexp, inexp);
				printf("\nInfix expression: %s\n", inexp);
				break;
			case 2:
				post_pre(postexp, preexp);
				printf("\nPrefix expression: %s\n", preexp);
				break;
			default:
				printf("\nInvalid choice. Try again!\n");
			}
			break;
		case 4:
			printf("\nBye bye!\n");
			return 0;
		default:
			printf("\nInvalid choice. Try again!\n");
		}
	} while (choice1 != 4);

	return 0;
}
