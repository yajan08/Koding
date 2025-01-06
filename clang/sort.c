#include <stdio.h>

struct student
{
    int roll, div;
    char name[20];
};

void acceptInfo(struct student s[100], int n)
{
    printf("\nEnter student information:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter division: ");
        scanf("%d", &s[i].div);
        printf("\n");
    }
}

void displayInfo(struct student s[100], int n)
{
    printf("\n----------------------------------------- Student Information -----------------------------------------\n");
    printf("\nRoll no.\tName\t\tDivision\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%d\n", s[i].roll, s[i].name, s[i].div);
    }
}

void bubbleSort(struct student s[100], int n)
{
    struct student temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (s[j].roll > s[j + 1].roll)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
}

void selectionSort(struct student s[100], int n)
{
    struct student temp;
    int minpos;
    for (int i = 0; i <= n - 2; i++)
    {
        minpos = i;
        for (int j = i + 1; j <= n - 1; j++)
            if (s[j].roll < s[minpos].roll)
                minpos = j;
        if (minpos != i)
        {
            temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
    }
}

void insertionSort(struct student s[100], int n)
{
    struct student key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = s[i];
        j = i - 1;
        while (j >= 0 && s[j].roll > key.roll)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void shellSort(struct student s[100], int n)
{
    int gap = n / 2, swapped;
    struct student temp;
    do
    {
        do
        {
            swapped = 0;
            for (int i = 0; i < n - gap; i++)
            {
                if (s[i].roll > s[i + gap].roll)
                {
                    temp = s[i];
                    s[i] = s[i + gap];
                    s[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while ((gap = gap / 2) >= 1);
}

int main()
{
    int n, choice;
    printf("\n\nWelcome to Student Information Systems\n");

    do
    {
        printf("\nEnter the number of students to continue: ");
        scanf("%d", &n);
        struct student s[n];
        
        acceptInfo(s, n);
        printf("Raw data:\n");
        displayInfo(s, n);

        printf("\nPlease choose the sort method:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n\nYour choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nData sorted using Bubble sort:\n");
            bubbleSort(s, n);
            break;

        case 2:
            printf("\nData sorted using Selection sort:\n");
            selectionSort(s, n);
            break;

        case 3:
            printf("\nData sorted using Insertion sort:\n");
            insertionSort(s, n);
            break;

        case 4:
            printf("\nThank you for using Student Information Systems.\n\n");
            return 0;

        default:
            printf("\nWrong choice! Choose again.\n");
        }

        displayInfo(s, n);

    } while (choice != 4);

    return 0;
}
