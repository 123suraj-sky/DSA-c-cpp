#include <stdio.h>
#define MAX 100 // length of array

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Code for Insertion
int indDeletion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
        return -1; // insertion is not successful

    // Shift each element to the right after index to insert element at index position
    for (int i = size - 1; i >= index; i--)
        arr[i + 1] = arr[i];

    arr[index] = element;
    return 1;
}

int main()
{
    int arr[MAX] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3; // size is size of the array & element is element to inserted in the array "arr" & index is the index where the element is inserted

    display(arr, size);
    int testInsertion = indDeletion(arr, size, element, MAX, index);

    if (testInsertion == 1)
    {
        size++;
        printf("\nInsertion Successfull\n");
        display(arr, size);
    }
    else
        printf("\nInsertion Not Successfull\n");

    return 0;
}