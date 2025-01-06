#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *stack[STACK_SIZE];
int top = -1;

int isStackEmpty()
{
	return top == -1;
}

void push(struct tnode *node)
{
	if (top == STACK_SIZE - 1) {
		printf("\nStack Overflow!\n");
		return;
	}
	stack[++top] = node;
}

struct tnode *pop()
{
	if (isStackEmpty()) {
		printf("\nStack Underflow!\n");
		return NULL;
	}
	return stack[top--];
}

void createbt_nr(struct tnode *root)
{
    char choice, cont;
    struct tnode *temp, *curr;
    int flag;

    do {
        temp = root;
        flag = 0;
        curr = (struct tnode *)malloc(sizeof(struct tnode));
        printf("\nEnter data for new node: ");
        scanf("%d", &curr->data);
        while (flag == 0) {
            printf("Do you want to add %d to the left or right of %d? (L/R): ", curr->data, temp->data);
            scanf(" %c", &choice);

            switch (choice) {
            case 'L':
            case 'l':
                if (temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                    printf("Node has been added.\n");
                }
                temp = temp->left;
                break;
            case 'R':
            case 'r':
                if (temp->right == NULL) {
                    temp->right = curr;
                    flag = 1;
                    printf("Node has been added.\n");
                }
                temp = temp->right;
                break;
            default:
                printf("\nInvalid choice! Node could not be added.\n");
            }
        }
        printf("\nDo you want to add another node? (Y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'Y' || cont == 'y');
}

void createbt_r(struct tnode *temp)
{
	struct tnode *curr;
	char choice;
	printf("\nDo you want to add a left child of %d? (Y/n): ", temp->data);
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {
		curr = (struct tnode *)malloc(sizeof(struct tnode));
		printf("Enter data for the left child of %d: ", temp->data);
		scanf("%d", &curr->data);
		curr->left = NULL, curr->right = NULL;
		temp->left = curr;
		createbt_r(curr);
	}

	printf("\nDo you want to add a right child of %d? (Y/n): ", temp->data);
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y') {
		curr = (struct tnode *)malloc(sizeof(struct tnode));
		printf("Enter data for the right child of %d: ", temp->data);
		scanf("%d", &curr->data);
		curr->left = NULL, curr->right = NULL;
		temp->right = curr;
		createbt_r(curr);
	}
}

void inorder_nr(struct tnode *temp)
{
	while (1) {
		while (temp != NULL) {
			push(temp);
			temp = temp->left;
		}

		if (isStackEmpty())
			break;

		temp = pop();
		printf("\t%d", temp->data);
		temp = temp->right;
	}
}

void inorder_r(struct tnode *temp)
{
    if (temp != NULL) {
        inorder_r(temp->left);
        printf("\t%d", temp->data);
        inorder_r(temp->right);
    }
}

void preorder_nr(struct tnode *temp)
{
	while (1) {

	}
}

void preorder_r(struct tnode *temp)
{
    if (temp != NULL) {
        printf("\t%d", temp->data);
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void postorder_nr(struct tnode *temp)
{
	while(1) {
		while (temp != NULL) {
			push (temp);
			temp = temp->left;
		}

		if (stack[top]->right == NULL) {
			temp = pop();
			printf("\t%d", temp->data);
		}

		while (!isStackEmpty() && stack[top]->right == temp) {
			temp = pop();
			printf("\t%d", temp->data);
		}

		if (isStackEmpty())
			break;
		
		temp = stack[top]->right;
	}
}

void postorder_r(struct tnode *temp)
{
    if (temp != NULL) {
        postorder_r(temp->left);
        postorder_r(temp->right);
        printf("\t%d", temp->data);
    }
}

int main()
{
    struct tnode *root;
	int choice;

	while (1) {
		printf("\nChoose operation:\n1 - Create tree (non-recursive)\n2 - Create tree (recursive)\n3 - Inorder traversal (recursive)\n4 - Preorder traversal (recursive)\n5 - Postorder traversal (recursive)\n6 - Inorder traversal (non-recursive)\n7 - Preorder traversal (non-recursive)\n8 - Postorder traversal (non-recursive)\n9 - Exit\n\nYour choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			root = (struct tnode *)malloc(sizeof(struct tnode));
			printf("\nEnter data for root node: ");
    		scanf("%d", &root->data);
    		root->left = NULL, root->right = NULL;

    		createbt_nr(root);
			printf("\nBinary tree created non-recursively.\n");
			break;
		
		case 2:
			root = (struct tnode *)malloc(sizeof(struct tnode));
			printf("\nEnter data for root node: ");
    		scanf("%d", &root->data);
    		root->left = NULL, root->right = NULL;

    		createbt_r(root);
			printf("\nBinary tree created recursively.\n");
			break;

		case 3:
			printf("\nInorder traversal of current binary tree (recursive):");
    		inorder_r(root);
			printf("\n");
			break;

		case 4:
			printf("\nPreorder traversal of current binary tree (recursive):");
    		preorder_r(root);
			printf("\n");
			break;

		case 5:
			printf("\nPostorder traversal of current binary tree (recursive):");
    		postorder_r(root);
			printf("\n");
			break;

		case 6:
			printf("\nInorder traversal of current binary tree (non-recursive):");
    		inorder_nr(root);
			printf("\n");
			break;

		case 7:
			printf("\nPreorder traversal of current binary tree (non-recursive):");
    		preorder_nr(root);
			printf("\n");
			break;

		case 8:
			printf("\nPostorder traversal of current binary tree (non-recursive):");
    		postorder_nr(root);
			printf("\n");
			break;

		case 9:
			char ch;
			printf("\nDo you really want to exit? (Y/n): ");
			scanf(" %c", &ch);
			if (ch == 'Y' || ch == 'y') {
				printf("\nYou have chosen to exit. Bye bye.\n\n");
				return 0;
			}
			break;

		default:
			printf("\nInvalid input! Try again.\n");
		}
	}
}
