#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool push(queue* target, int value)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->prev = NULL;
    if (target->head != NULL)
    {
        target->head->prev = new_node;
    }
    else
    {
        target->tail = new_node;
    }
    target->head = new_node;
    target->num++;
    return true;
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
    int n;
    scanf("%d", &n);

    queue q = {};
    for (int i = 1; i <= n; i++)
    {
        push(&q, i);
    }
    for (int i = 1; i < n; i++)
    {
        pop(&q);
        push(&q, pop(&q));
    }
    printf("%d", pop(&q));

    return 0;
}