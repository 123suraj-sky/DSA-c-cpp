#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin; // index of minimum value
    int temp; // for swapping values
    printf("After running selection sort ...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        //* Swapping values
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {3, 5, 2, 132, 1};
    int n = sizeof(A) / sizeof(int);
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    //notes: there will be total n - 1 passes

    return 0;
}