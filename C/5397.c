#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node* prev;
    struct node* next;
} node;

node* head, * tail, * cursor;

void init()
{
    head = (node*) malloc(sizeof(node));
    tail = (node*) malloc(sizeof(node));

    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;

    cursor = head;
}

void move(char data)
{
    if (data == '<')
        if (cursor != head)
            cursor = cursor->prev;
    if (data == '>')
        if (cursor != tail->prev)
            cursor = cursor->next;
}

void insert(char data)
{
    node* ptr = (node*) malloc(sizeof(node));
    ptr->data = data;

    ptr->next = cursor->next;
    cursor->next->prev = ptr;
    cursor->next = ptr;
    ptr->prev = cursor;

    cursor = cursor->next;
}

void delete()
{
    if (cursor != head)
    {
        node* delNode = cursor;
        cursor = cursor->prev;
        cursor->next = delNode->next;
        cursor->next->prev = cursor;
        free(delNode);
    }
}

void print()
{
    node* print = head->next;
    while (print != tail)
    {
        printf("%c", print->data);
        print = print->next;
    }
    printf("\n");
}

void delete_list()
{
    if (head->next != tail)
    {
        node* delList = head->next;
        while (delList != tail)
            delList = delList->next;

        head->prev = head;
        head->next = tail;
        tail->prev = head;
        tail->next = tail;
        cursor = head;
    }
}

int main()
{
    int testCase;
    scanf("%d\n", &testCase);

    char data;
    init();

    for (int i = 0; i < testCase; i++)
    {
        while (1)
        {
            data = getchar();
            if (data == '\n')
                break;
            if (data == '<' || data == '>')
                move(data);
            else if (data == '-')
                delete();
            else
                insert(data);
        }
        print();
        delete_list();
    }
    free(head);
    free(tail);

    return 0;
}