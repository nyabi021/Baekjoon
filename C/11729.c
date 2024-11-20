#include <stdio.h>

void hanoi(int height, int start, int by, int dest)
{
    if (height == 1)
    {
        printf("%d %d\n", start, dest);
        return;
    }
    hanoi(height - 1, start, dest, by);
    printf("%d %d\n", start, dest);

    hanoi(height - 1, by, start, dest);
}


int main()
{
    int n;
    scanf("%d", &n);
    int k = 1;
  
    for (int i = 0; i < n; i++)
    {
        k *= 2;
    }
    k--;
    printf("%d\n", k);
    hanoi(n, 1, 2, 3);
    return 0;
}

