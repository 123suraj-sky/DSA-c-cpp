// Depth First Search

#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // visited matrix for tracked notes
int a[7][7] = {{0, 1, 1, 1, 0, 0, 0},
               {1, 0, 1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1, 0, 0},
               {1, 0, 1, 0, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 1},
               {0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 1, 0, 0}}; // adjacent matrix --> to fill matrix see notes of 87 where graph is given

void DFS(int i)
{
    printf("%d\t", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(4);

    return 0;
}