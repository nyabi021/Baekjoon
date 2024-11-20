#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_entry
{
    int value;
    struct stack_entry* below;
} stack_entry;

typedef struct stack
{
    int num;
    struct stack_entry* top;
} stack;

bool is_stack_valid(stack* target)
{
    return target != NULL;
}

bool is_stack_empty(stack* target)
{
    if (is_stack_valid(target))
    {
        return target->top == NULL;
    }
    return true;
}

bool push(stack* target, int value)
{
    if (is_stack_valid(target) == false)
    {
        return false;
    }

    stack_entry* ptr = (stack_entry*) malloc(sizeof(stack_entry));
    ptr->value = value;
    ptr->below = target->top;
    target->top = ptr;
    target->num += 1;

    return true;
}

stack_entry* pop(stack* target)
{
    if (is_stack_valid(target) == false)
    {
        return NULL;
    }
    stack_entry* ptr = target->top;
    target->top = ptr->below;
    target->num -= 1;
    return ptr;
   
}


int main()
{
    int k;
    scanf("%d", &k);

    stack stk = {};

    stack ans;

    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);

        if (x != 0)
        {
            push(&stk, x);
        }
        else
        {
            pop(&stk);
        }
    }

    int temp = stk.num;
    int result = 0;

    for (int i = 0; i < temp; i++)
    {
        result += pop(&stk)->value;
    }
    printf("%d\n", result);
    return 0;
}
