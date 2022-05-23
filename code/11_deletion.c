#include <stdio.h>
#define MAX 100 // length of array

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Code for Deletion
void indDeletion(int arr[], int size, int index)
{
    // Shift each element to the right after index to insert element at index position
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
}

int main()
{
    int arr[MAX] = {7, 8, 12, 27, 88};
    int size = 5, index = 1; // size is size of the array & index is the index where the element to be deleted

    display(arr, size);
    indDeletion(arr, size, index);
    size--;
    display(arr, size);

    return 0;
}