#include <stdio.h>

int preorder[1001];
int inorder[1001];

void solution(int root, int s, int e)
{
    for (int i = s; i < e; i++)
    {
        if (inorder[i] == preorder[root])
        {
            solution(root + 1, s, i);
            solution(root + i + 1 - s, i + 1, e);
            printf("%d ", preorder[root]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &preorder[j]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &inorder[j]);
        }
        solution(0, 0, n);
        printf("\n");
    }

    return 0;
}
