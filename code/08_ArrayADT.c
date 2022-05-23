#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize) // tSize is total size and uSize is used size
{
    // (*a).totalSize = tSize;
    // (*a).usedSize = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));

    //notes: both above and below code are same

    a->totalSize = tSize;
    a->usedSize = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->usedSize; i++)
        printf("%d\n", (a->ptr)[i]);
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);

    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show now\n");
    show(&marks);

    return 0;
}
