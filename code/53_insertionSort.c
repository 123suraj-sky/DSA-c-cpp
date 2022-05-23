#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // Loop for passes
    {
        key = A[i]; // element which is giong to insert at left side array --> see notes in lecture 52
        j = i - 1;  // j is left side array

        // Loop for each pass
        while (j >= 0 && A[j] > key) // It will sort in acending order
        //notes: if we want to sort in decending order then "A[j] < key"
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {1, 2, 13, 34, 25, 16, 7};
    int n = sizeof(A) / sizeof(int); // size

    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}