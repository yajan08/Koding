#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	char word[20], meaning[50];
	struct tnode *left, *right;
};

void createbst(struct tnode *root)
{
    char cont;
    struct tnode *temp, *curr;
    int flag;

    do {
    	temp = root;
        flag = 0;
        curr = (struct tnode *)malloc(sizeof(struct tnode));
        printf("\nEnter new word: ");
        scanf("%s", curr->word);
        printf("Enter meaning: ");
        scanf("%s", curr->meaning);
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0) {
        	if (strcmp(curr->word, temp->word) < 0) {
        		if (temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                    printf("Word has been added to the dictionary.\n");
                }
       			temp = temp->left;
        	}
        	else if (strcmp(curr->word, temp->word) > 0) {
        		if (temp->right == NULL) {
        			temp->right = curr;
                    flag = 1;
                    printf("Word has been added to the dictionary.\n");
                }
       			temp = temp->right;
        	}
        	else {
        		printf("\nGiven word already exists in the dictionary! Node could not be added.\n");
        		break;
        	}
        }
        printf("\nDo you want to add another node? (Y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'Y' || cont == 'y');
}

void inorder_r(struct tnode *temp)
{
    if (temp != NULL) {
        inorder_r(temp->left);
        printf("\n%s\t%s", temp->word, temp->meaning);
        inorder_r(temp->right);
    }
}

struct tnode *delete(struct tnode *root, char key[])
{
	int flag = 0;
	struct tnode *curr = root, *parent = NULL, *temp, *s;
	while (curr != NULL) {
		if(strcmp(curr->word, key) == 0) {
			flag = 1;
			break;
		}
		else if (strcmp(key, curr->word) < 0) {
			parent = curr;
			curr = curr->left;
		}
		else {
			parent = curr;
			curr = curr->right;
		}
	}

	if (flag == 0) {
		printf("\nThe word \"%s\" doesn't exist in the dictionary!\n", key);
		return root;
		
	}
	if (curr == root) {
		if (curr->right == NULL)
			root = root->left;
		else if (curr->left == NULL)
			root = root->right;
		else if (curr->right != NULL && curr->left != NULL) {
			temp = curr->left;
			root = curr->right;
			s = curr->right;
			while (s->left != NULL) {
				s = s->left;
			}
			s->left = temp;
		}
	}
	else if (curr->left == NULL && curr->right == NULL) {
		if (parent->left == curr)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	else if (curr->left == NULL) {
		if (parent->left == curr)
			parent->left = curr->right;
		else
			parent->right = curr->right;
	}
	else if (curr->right == NULL) {
		if (parent->left == curr)
			parent->left = curr->left;
		else
			parent->right = curr->left;
	}
	else {
		s = curr->right;
		temp = curr->left;
		while (s->left != NULL) {
			s = s->left;
		}
		s->left = temp;
		if (parent->left == curr)
			parent->left = curr->right;
		else
			parent->right = curr->right;
	}
	curr->left = NULL;
	curr->right = NULL;
	free(curr);
	printf("\nThe word \"%s\" has been deleted from the dictionary.\n", key);
	return root;
}

#define size 100
int front = -1, rear = -1;
struct tnode *queue[size];

int isEmpty()
{
	return rear == front;
}

int isFull()
{
	return rear == size - 1;
}

void addQ(struct tnode *temp)
{
	if (isFull()) {
		printf("\nQueue overflow.\n");
		return;
	}
	queue[++rear] = temp;
}

struct tnode *delQ()
{
	if (isEmpty()) {
		printf("\nQueue underflow.\n");
		return NULL;
	}
	return queue[++front];
}

void bfs(struct tnode *root)
{
	if (root == NULL) {
		printf("\nBinary search tree is empty!\n");
		return;
	}
	int p = 1, r = 0;
	struct tnode *temp = root;
	addQ(temp);
	while (!isEmpty())
	{
		for (int i = 0; i < p; i++) {
			temp = delQ();
			printf("%s\t", temp->word);
			if (temp->left != NULL) {
				addQ(temp->left);
				r++;
			}
			if (temp->right != NULL) {
				addQ(temp->right);
				r++;
			}
		}
		printf("\n");
		p = r;
		r = 0;
	}
}

struct tnode *copy_r(struct tnode *root)
{
	struct tnode *temp = NULL;
	if (root != NULL) {
		temp = (struct tnode *)malloc(sizeof(struct tnode));
		strcpy(temp->word, root->word);
		strcpy(temp->meaning, root->meaning);
		temp->left = copy_r(root->left);
		temp->right = copy_r(root->right);
	}
	return temp;
}

void mirror_r(struct tnode *root)
{
	struct tnode *temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left != NULL)
		mirror_r(root->left);
	if (root->right != NULL)
		mirror_r(root->right);
}

void mirror_nr(struct tnode *root)
{
	struct tnode *temp = root, *swap;
	addQ(temp);

	while (!isEmpty()) {
		temp = delQ();
		swap = temp->left;
		temp->left = temp->right;
		temp->right = swap;
		if (temp->left != NULL)
			addQ(temp->left);
		if (temp->right != NULL)
			addQ(temp->right);
	}
	printf("\nMirrored tree:\n\n");
	bfs(root);
}

int main()
{
	struct tnode *root, *rootcpy;
	int choice;

	while (1) {
		printf("\nChoose operation:\n1 - Create dictionary\n2 - Delete a word\n3 - Display (Inorder traversal)\n4 - Copy\n5 - Breadth-first traversal\n6 - Mirror (Recursive)\n7 - Mirror (Non-recursive)\n8 - Exit\n\nYour choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			root = (struct tnode *)malloc(sizeof(struct tnode));
    		printf("\nEnter first word: ");
    		scanf("%s", root->word);
    		printf("Enter meaning: ");
    		scanf("%s", root->meaning);
    		root->left = NULL;
    		root->right = NULL;

    		createbst(root);
			printf("\nDictionary has been created.\n");
			break;

		case 2:
			char key[20];
			printf("\nEnter word to delete:\n");
			scanf("%s", key);
			root = delete(root, key);
			printf("\n");
			break;

		case 3:
			printf("\nWords available in the dictionary:\n");
			inorder_r(root);
			printf("\n\n");
			break;

		case 4:
			rootcpy = copy_r(root);
			printf("\nDictionary has been copied recursively.\n\nCopied dictionary is:\n");
			inorder_r(rootcpy);
			printf("\n\n");
			break;

		case 5:
			printf("\nBreadth-first traversal of the dictionary:\n\n");
			bfs(root);
			printf("\n");
			break;

		case 6:
			printf("\nOriginal tree:\n\n");
			bfs(root);
			printf("\n");
			mirror_r(root);
			printf("\nMirrored tree:\n\n");
			bfs(root);
			printf("\n");
			break;

		case 7:
			printf("\nOriginal tree:\n\n");
			bfs(root);
			printf("\n");
			mirror_nr(root);
			printf("\n");
			break;

		case 8:
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
