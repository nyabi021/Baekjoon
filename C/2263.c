#include <stdio.h>

int in[100000], post[100000];

void order(int in_l, int in_r, int post_l, int post_r)
{
    int i;
    if (post_l <= post_r)
    {
        int head = post[post_r];
        printf("%d ", head);
        for (i = in_l; in[i] != head; i++);
        int l_num = i - in_l;
        int r_num = in_r - i;
        order(in_l, in_l + l_num - 1, post_l, post_l + l_num - 1);
        order(in_r - r_num + 1, in_r, post_r - r_num, post_r - 1);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &post[i]);
    order(0, n - 1, 0, n - 1);
    return 0;
}