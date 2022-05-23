#include <stdio.h>
#include <stdbool.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n) // this bubble sort is not adaptive
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of passes
    {
        for (int j = 0; j < (n - 1 - i); j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1]) // swap values if next is lesser number
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

//* following is better for bubble sort
void bubbleSortAdaptive(int *A, int n) // this bubble sort is adaptive
{
    int temp;
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++) // For number of passes
    {
        printf("Working on pass number: %d\n", i + 1);
        isSorted = true;
        for (int j = 0; j < (n - 1 - i); j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1]) // swap values if next is lesser number
            {
                isSorted = false;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(A) / sizeof(int); // size

    printArray(A, n); // Before sorting
    // bubbleSort(A, n); // Bubble sort method for sorting
    bubbleSortAdaptive(A, n);
    printArray(A, n); // After sorting

    return 0;
}