#include <stdio.h>
#include <stdlib.h>

struct node
{
	int prn;
	char name[20];
	struct node *next;
};

void create(struct node *H)
{
	struct node *temp = H, *curr;
	char choice = 'Y';

	while (choice == 'Y' || choice == 'y') {
		curr = (struct node *)malloc(sizeof(struct node));

		printf("\nEnter PRN: ");
		scanf("%d", &curr->prn);
		printf("Enter name: ");
		scanf("%s", curr->name);

		curr->next = NULL;
		temp->next = curr;
		temp = curr;

		printf("\nDo you wish to add another member? (Y/n): ");
		scanf(" %c", &choice);
	}
}

void display(struct node *H)
{
	struct node *curr;

	if (H->next == NULL)
		printf("\n*List is empty!*\n");
	else {
		curr = H->next;
		printf("\nPRN\t\tName\n");
		while (curr != NULL) {
			printf("%d\t%s", curr->prn, curr->name);
			if (curr == H->next)
				printf("\t(President)");
			else if (curr->next == NULL)
				printf("\t(Secretary)");
			else
				printf("\t(Member)");
			printf("\n");
			curr = curr->next;
		}
	}
}

int len(struct node *H)
{
	struct node *curr;
	curr = H->next;
	int count = 0;

	while (curr != NULL) {
		count++;
		curr = curr->next;
	}

	return count;
}

void insertbypos(struct node *H)
{
	int i=1, pos, k=len(H);
	struct node *curr = H;
	struct node *nnode = (struct node *)malloc(sizeof(struct node));
	
	printf("\nEnter position: ");
	scanf("%d", &pos);
	
	if (pos > k + 1)
		printf("\nData cannot be inserted at given position!\n");
        
	else {
	    
        printf("\nEnter data for new node:\nEnter PRN: ");
	    scanf("%d", &nnode->prn);
	    printf("Enter name: ");
	    scanf("%s", nnode->name);
	
		while (curr != NULL && i < pos) {
			i++;
			curr = curr->next;
		}
		
		nnode->next = curr->next;
		curr->next = nnode;
	    
        printf("\nData added successfully!\n");
	}
	
}

void delpos(struct node *H)
{
	struct node *prev = H, *curr = H->next;
	int ctr = 1, pos, k = len(H);
	
	printf("\nEnter the position of the data you want to delete: ");
	scanf("%d", &pos);
	
	if (k < pos)
		printf("\nNon-existent data cannot be deleted.\n");
	else {
		
		while (curr != NULL && ctr < pos) {
			ctr++;
			prev = curr;
			curr = curr->next;
		}
		
		struct node *temp = curr;
		prev->next = curr->next;
		curr->next = NULL;
		free(temp);
	}
}

void reverse(struct node *H)
{
	struct node *prev = NULL, *curr = H->next, *future;
	
	while (curr != NULL) {
		future = curr->next;
		curr->next=prev;
		prev = curr;
		curr = future;
	}
	
	H->next = prev;
	printf("\nThe linked list has been reversed.\n");
}

void sort(struct node *H)
{
	int l = len(H);
	struct node *prev, *curr, *temp;
	
	for (int i = 1; i <= l - 1; i++) {
		
		prev = H;
		curr = H->next;
		
		for (int j = 0; j < l - i; j++) {
			
			temp = curr->next;
			
			if (curr->prn > temp->prn) {
				prev->next = temp;
				curr->next = temp->next;
				temp->next = curr;
				prev = temp;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
	
	printf("\nLinked list has been sorted successfully.\n");
}

void merge(struct node *H1, struct node *H2)
{
	sort(H1);
	sort(H2);
	
	struct node *curr1 = H1->next, *curr2 = H2->next, *temp;
	int flag;
	
	if (curr1->prn < curr2->prn) {
		temp = H1;
		flag = 1;
	} else {
		temp = H2;
		flag = 0;
	}
	
	while (curr1 != NULL && curr2 != NULL) {
		if (curr1->prn < curr2->prn) {
			temp->next = curr1;
			temp = curr1;
			curr1 = curr1->next;
		} else {
			temp -> next = curr2;
			temp = curr2;
			curr2 = curr2->next;
		}
	}
	
	if (curr1 == NULL)
		temp->next = curr2;
	else
		temp->next = curr1;
		
	printf("\nMerged linked list:\n");
		
	if (flag == 1)
		display(H1);
	else
		display(H2);
}

int main()
{
	struct node *head1 = (struct node *)malloc(sizeof(struct node));
	head1->next = NULL;
	
	struct node *head2 = (struct node *)malloc(sizeof(struct node));
	head2->next = NULL;
	
	int choice = 0;
	
	printf("\nTo start, create a link list by adding data:\n");
	create(head1);
	display(head1);
	
	do {
		printf("\nChoose operation:\n1 - Insert new data\n2 - Delete data\n3 - Display count\n4 - Reverse linked list\n5 - Sort list\n6 - Merge with another list\n7 - Exit\n\nYour choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			insertbypos(head1);
			display(head1);
			break;
		case 2:
			delpos(head1);
			display(head1);
			break;
		case 3:
			printf("\nNumber of entries: %d\n", len(head1));
			break;
		case 4:
			reverse(head1);
			display(head1);
			break;
		case 5:
			sort(head1);
			display(head1);
			break;
		case 6:
			printf("\nEnter data for new linked list:\n\n");
			create(head2);
			merge(head1, head2);
			break;
		case 7:
			printf("\nYou have chosen to exit. Bye bye.\n\n");
			return 0;
		}
	} while (choice);
}
