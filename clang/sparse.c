#include <stdio.h>
#include <stdlib.h>

void acceptMatrix(int A[100][100], int m, int n)
{
    printf("\nEnter data for matrix:\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element for index (%d, %d): ", i, j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(int A[100][100], int m, int n)
{
    printf("\nInput matrix:\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void compact(int A[100][100], int m, int n, int B[100][3])
{
    B[0][0] = m;
    B[0][1] = n;

    int k = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;
}

void displayCompact(int A[100][3])
{
    for (int i = 0; i <= A[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void simpleTranspose(int B[100][3], int C[100][3])
{
    int m = B[0][0], n = B[0][1], t = B[0][2];
    C[0][0] = n, C[0][1] = m, C[0][2] = t;

    if (t <= 0)
    {
        return;
    }
    int q = 1;
    for (int col = 0; col < n; col++)
    {
        for (int p = 1; p <= t; p++)
        {
            if (B[p][1] == col)
            {
                C[q][0] = B[p][1];
                C[q][1] = B[p][0];
                C[q][2] = B[p][2];
                q++;
            }
        }
    }
}

void fastTranspose(int B[100][3], int C[100][3])
{
    int m = B[0][0], n = B[0][1], t = B[0][2];
    C[0][0] = n, C[0][1] = m, C[0][2] = t;

    if (t <= 0)
    {
        return;
    }

    int S[n], T[n];

    for (int i = 0; i < n; i++)
        S[i] = 0;

    for (int i = 1; i < t; i++)
        S[B[i][1]]++;

    T[0] = 1;
    for (int i = 1; i < n; i++)
        T[i] = T[i - 1] + S[i - 1];

    for (int i = 1; i <= t; i++)
    {
        int j = B[i][1];
        C[T[j]][0] = B[i][1], C[T[j]][1] = B[i][0], C[T[j]][2] = B[i][2];
        T[j]++;
    }
}

int main(void)
{
    int m, n, choice = 0;

     while (choice != 3)
    {
        printf("\n\nChoose an operation:\n1 - Simple Transpose\n2 - Fast Transpose\n3 - Exit\n\nYour choice: ");
        scanf("%d", &choice);

        printf("\nEnter number of rows: ");
        scanf("%d", &m);
        printf("Enter number of columns: ");
        scanf("%d", &n);
        int A[m][n], B[m * n][3], C[m * n][3];

        switch (choice)
        {
        case 1:
            acceptMatrix(A, m, n);
            displayMatrix(A, m, n);

            compact(A, m, n, B);

            printf("\nCompact form of the matrix:\n\n");
            displayCompact(B);

            simpleTranspose(B, C);

            printf("\nSimple Transposed compact form of the matrix:\n\n");
            displayCompact(C);
            break;

        case 2:
            acceptMatrix(A, m, n);
            displayMatrix(A, m, n);

            compact(A, m, n, B);

            printf("\nCompact form of the matrix:\n\n");
            displayCompact(B);

            fastTranspose(B, C);

            printf("\nFast Transposed compact form of the matrix:\n\n");
            displayCompact(C);
            break;

        case 3:
            printf("\nYou have chosen to exit. Bye bye!\n\n");
            return 0;

        default:
            printf("\nInvalid operation! Try again.\n");
        }
    }
}