#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2; // it automatically gives G.I.F
                                // For eg. 11/2 = 5 as mid is also a integer
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            low = mid + 1; // since we already search for mid in previous if condition
        else
            high = mid - 1; // since we already search for mid in previous if condition
    }
    return -1;
}

int main()
{
    int arr1[] = {1, 2, 4, 56, 4, 3, 23, 5, 4643, 5, 234};
    int arr2[] = {1, 2, 3, 4, 4, 5, 5, 23, 56, 234, 4643};
    int size = sizeof(arr1) / sizeof(int); // arr1 and arr2 are same only difference is that arr1 is not sorted while arr2 is sorted
    int element = 56;

    int searchIndex1 = linearSearch(arr1, size, element);
    int searchIndex2 = binarySearch(arr2, size, element);

    if (searchIndex1 == -1 && searchIndex2 == -1)
        printf("Element not found\n");
    else
    {
        printf("Using linearSearch the element %d was found at index %d\n", element, searchIndex1);
        printf("Using binarySearch the element %d was found at index %d\n", element, searchIndex2);
    }
    return 0;
}