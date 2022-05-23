#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MAX

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

// Find the maximum element in A
int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j; // 'j' is counter for given array A and 'i' counter for count array

    // Find the maximum element in A
    int max = maximum(A, n);

    // dynamic memory allocation in array
    // create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // initialize count array to zero
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // updating count array regarding array A
    // increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    i = 0;
    j = 0;
    // while (i < max + 1)
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {3, 5, 2, 1, 34, 4, 34, 4, 5};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);
    countSort(A, n);
    printArray(A, n);

    return 0;
}