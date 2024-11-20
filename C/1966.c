#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* prev;
} node;

typedef struct queue
{
    int num;
    struct node* head;
    struct node* tail;
} queue;

void push(queue* target, int value)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    if (target->head == NULL)
    {
        target->tail = new_node;
    }
    else
    {
        target->head->prev = new_node;
    }
    target->head = new_node;
    target->num++;
}

int pop(queue* target)
{
    node* temp = target->tail;
    int result = temp->value;
    target->tail = temp->prev;
    target->num--;
    if (target->num == 0)
    {
        target->head = NULL;
    }
    free(temp);
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    int arr[101];

    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int count = 0;
        queue q = {};


        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            push(&q, i);
        }
        while (q.num != 0)
        {
            int temp = pop(&q);

            for (int i = 0; i < n; i++)
            {
                if (arr[temp] < arr[i])
                {
                    push(&q, temp);
                    temp = -1;
                    break;
                }
            }
            if (temp != -1)
            {
                count++;
                arr[temp] = 0;
                if (temp == m)
                {
                    printf("%d\n", count);
                    break;
                }
            }
        }
    }

    return 0;
}