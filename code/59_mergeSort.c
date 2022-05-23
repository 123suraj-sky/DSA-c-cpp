#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100]; // we have taken max size 100
    // we can also dynamic allocate size = high - low + 1
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            // k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            // k++;
        }
        k++;
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    // copying all elements of A to B
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        // any other strategy can be followed to calculate mid
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int A[] = {3, 5, 2, 1, 34, 4, 34, 4, 5};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);
    mergeSort(A, 0, n - 1);
    printArray(A, n);

    return 0;
}