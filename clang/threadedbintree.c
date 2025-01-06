#include <stdio.h>
#include <stdlib.h>

struct tbtnode {
    char data;
    int rbit, lbit;
    struct tbtnode *right, *left;
};

void create(struct tbtnode *head)
{
    struct tbtnode *root = (struct tbtnode *)malloc(sizeof(struct tbtnode)), *temp, *curr;
    int flag;
    char choice, cont;
    printf("\nEnter data for root node: ");
    scanf(" %c", &root->data);
    head->lbit = 1;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    head->left = root;

    do {
        flag = 0;
        temp = root;
        curr = (struct tbtnode *)malloc(sizeof(struct tbtnode));
        printf("\nEnter data for next node: ");
        scanf(" %c", &curr->data);
        curr->lbit = curr->rbit = 0;

        while (flag == 0) {
            printf("\nDo you want to add %c to the left or right of %c? (L/R): ", curr->data, temp->data);
            scanf(" %c", &choice);
            if (choice == 'l' || choice == 'L') {
                if (temp->lbit == 0) {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    flag = 1;
                    printf("Node has been added.\n");
                }
                else
                    temp = temp->left;
            }
            else if (choice == 'r' || choice == 'R') {
                if (temp->rbit == 0) {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 1;
                    flag = 1;
                    printf("Node has been added.\n");
                }
                else
                    temp = temp->right;
            }
            else {
                printf("\nInvalid choice! Node could not be added.\n");
            }
        }
        printf("\nDo you want to add another node? (Y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'Y' || cont == 'y');
}

struct tbtnode *inordersucc(struct tbtnode *temp)
{
    struct tbtnode *x = temp->right;
    if (temp->rbit == 1)
        while (x->lbit == 1)
            x = x->left;

    return x;
}

void inorder(struct tbtnode *head)
{
    struct tbtnode *temp = head;
    printf("\nInorder traversal of the threaded binary tree:\n\n");
    while (1) {
        temp = inordersucc(temp);
        if (temp == head)
            break;
        printf("\t%c", temp->data);
    }
    printf("\n\n");
}

void preorder(struct tbtnode *head)
{
    struct tbtnode *temp = head->left;
    printf("\nPreorder traversal of the threaded binary tree:\n\n");
    while (temp != head) {
        printf("\t%c", temp->data);
        while (temp->lbit != 0) {
            temp = temp->left;
            printf("\t%c", temp->data);
        }
        
        while (temp->rbit == 0)
            temp = temp->right;

        temp = temp->right;
    }
    printf("\n\n");
}

int main()
{
    struct tbtnode *head = (struct tbtnode *)malloc(sizeof(struct tbtnode));
    head->rbit = 1;
    head->lbit = 0;
    head->left = head;
    head->right = head;
    create(head);
    inorder(head);
    preorder(head);
    return 0;
}